//Toma Dimov | Lab-27 | COMP210

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <cctype>
using namespace std;

int MAXFRIENDSHIP = 10; int MINFRIENDSHIP = 0;

void displayVillagerStats(tuple<int,string,string>);
void displayAll(map<string, tuple<int,string,string>>);
void increaseFriendship(tuple<int,string,string> &v, int val); //takes negative as well

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerStats;

    // insert elements into the map
    villagerStats["Audie"] = {3, "Hummingbird", "Get a load of this."};
    villagerStats["Raymond"] = {5, "Whale", "Why the hurry?"};
    villagerStats.insert({"Marshal", {7, "Ape", "What's for dinner?"}});

    //Menu:
    while(true){
        int option;
        cout<<"1. Add Villager\n";
        cout<<"2. Delete Villager\n";
        cout<<"3. Increase Friendship\n";
        cout<<"4. Decrease Friendship\n";
        cout<<"5. Search for Villager\n";
        cout<<"6. Exit\n";
        cin>>option;
        if(option == 6)
            break;
        switch (option){
        case 1:{
            cout<<"Villager Name: ";
            string name;
            cin>>name;
            name[0] = toupper(name[0]);
            cout<<"Friendship Level: ";
            int friendship;
            cin>>friendship;
            cout<<"Species: ";
            string species;
            cin>>species;
            cout<<"Catchphrase: ";
            string catchphrase;
            cin>>catchphrase;
            tuple<int,string,string> v = {friendship, species, catchphrase};
            villagerStats.insert(make_pair(name, v));
            cout<< name <<" added."<<endl;
            break;
        }
        case 2:{
            cout<<"Enter villager to delete by name: "<<endl;
            string input;
            cin>>input;
            input[0] = toupper(input[0]);
            auto it = villagerStats.find(input);
            if (it == villagerStats.end()){
                cout<<"Villager not found. Returning to Main Menu.\n";
                break;
            }
            villagerStats.erase(it);
            cout<< input <<" deleted.\n";
            break;
        }
        case 3: //case 1 and 2 work the same way, but I use a ternary operator to make slight adjustments whether we are decreasing or increasing friendship.
        case 4: {//Increase or decrease friendship
            cout<<"Choose villager by name to " << string ((option == 3) ? "increase" : "decrease") << " their friendship.\n";   //prompt to choose villager by name
            string input;
            cin>>input;
            input[0] = toupper(input[0]); //uppercase the first letter
            auto it = villagerStats.find(input);
            if (it == villagerStats.end()){
                cout<<"Villager not found. Returning to Main Menu.\n";
                break;
            }
            cout<< it->first <<"'s current friendship is "<< get<0>(it->second)<<". "<< string ((option == 3) ? "Increase" : "Decrease") <<" friendship by how much ["<<MINFRIENDSHIP<<"-"<<MAXFRIENDSHIP<<"]: ";
            int value;
            cin>>value;

            increaseFriendship(it->second, ((option == 3)? value: -value)); //run it through the friendship increaser, ternary operator for decrease or increase
            cout<<input<<"'s friendship changed to "<<get<0>(it->second)<<endl;
            break; 
        }
        case 5:{
            cout<<"Enter villager to search by name: "<<endl;
            string input;
            cin>>input;
            input[0] = toupper(input[0]); //uppercase the first letter
            auto it = villagerStats.find(input);
            if (it == villagerStats.end()){
                cout<<"Villager not found. Returning to Main Menu.\n";
                break;
            }
            cout<<"Villager found\n";
            cout<<it->first<<"[";
            displayVillagerStats(it->second);
            break;
        }
        default:{
            break;
        }
        }
    displayAll(villagerStats);
    option = 0;
    }
    return 0;
}

void displayVillagerStats(tuple<int,string,string> v){
    auto[friendship, species, phrase]=v;
    cout<<friendship<<", "<<species<<", "<<phrase <<"]\n";
}

void displayAll(map<string, tuple<int,string,string>> m){
    cout<<"=======================================================\n";
    cout << "Villagers and their stats:" << endl;
    for (auto pair : m) {
        auto[friendship, species, phrase]=pair.second;
        cout << pair.first << " [";
        displayVillagerStats(pair.second);
    }
    cout<<"=======================================================\n";
}

void increaseFriendship(tuple<int,string,string> &v, int val){//takes negative as well
    get<0>(v) += val;
    //clamp values
    if(get<0>(v)>MAXFRIENDSHIP)
        get<0>(v) = MAXFRIENDSHIP;
    else if(get<0>(v)<MINFRIENDSHIP)
        get<0>(v) = MINFRIENDSHIP;
} 