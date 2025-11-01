//Toma Dimov | Lab-27 | COMP210

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int MAXFRIENDSHIP = 10; int MINFRIENDSHIP = 0; int TOTALSTATS = 3;

void displayVillagerStats(tuple<int,string,string>);
void displayAll(map<string, tuple<int,string,string>>);
void increaseFriendship(tuple<int,string,string> &v, int val); //takes negative as well
tuple<int,string,string> *searchForVillager(map<string, tuple<int,string,string>> m,string key);


int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerStats;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerStats["Audie"] = {3, "Hummingbird", "Get a load of this."};
    villagerStats["Raymond"] = {5, "Whale", "Why the hurry?"};
    villagerStats.insert({"Marshal", {7, "Ape", "What's for dinner?"}});
    //debug code
    //tuple<int,string,string> *temp = searchForVillager(villagerStats, "Audie");
    //displayVillagerStats(*temp);


    //Menu:
    while(true){
        int option;
        cout<<"1. Increase Friendship\n";
        cout<<"2. Decrease Friendship\n";
        cout<<"3. Search for Villager\n";
        cout<<"4. Exit\n";
        cin>>option;
        if(option == 4)
            break;
        switch (option){
        case 1:
        case 2: {//Increase or decrease friendship
            cout<<"Choose villager by name to " << ((option == 1)? "increase" : "decrease") << " their friendship\n";   //prompt to choose villager by name
            displayAll(villagerStats);//display villagers
            string input;
            cin>>input;
            auto it = villagerStats.find(input);
            if (it == villagerStats.end()){
                cout<<"Returning to Main Menu.\n";
                break;
            }
            cout<<"Increase Friendship by how much ["<<MINFRIENDSHIP<<"-"<<MAXFRIENDSHIP<<"]: ";
            int value;
            cin>>value;
            increaseFriendship(it->second, value); //run it through the friendship increaser
            displayVillagerStats(it->second);
            break;
        }
        {
            
            break;
        }
        case 3:{
            
            break;
        }
        default:{
            break;
        }
        } 
    } 
/**/
/*
    // delete an element
    villagerStats.erase("Raymond");

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerStats.size() << endl;
    villagerStats.clear();
    cout << "Size after clear: " << villagerStats.size() << endl;
*/
    displayAll(villagerStats);
    return 0;
}

void displayVillagerStats(tuple<int,string,string> v){
    auto[friendship, species, phrase]=v;
    cout<<friendship<<", "<<species<<", "<<phrase <<"]\n";
}

void displayAll(map<string, tuple<int,string,string>> m){
    cout << "Villagers and their stats:" << endl;
    for (auto pair : m) {
        auto[friendship, species, phrase]=pair.second;
        cout << pair.first << " [";
        displayVillagerStats(pair.second);
    }
}
/*
tuple<int,string,string> *searchForVillager(map<string, tuple<int,string,string>> m,string key){
    auto it = m.find(key);
    if (it != m.end()) {  // the iterator points to beyond the end of the map if key is not found
        tuple<int,string,string> *itptr = &(it->second);
        return itptr;

    } else
        cout << endl << key << " not found." << endl;
        return nullptr;
}*/

void increaseFriendship(tuple<int,string,string> &v, int val){//takes negative as well
    get<0>(v) += val;
    //clamp values
    if(get<0>(v)>MAXFRIENDSHIP)
        get<0>(v) = MAXFRIENDSHIP;
    else if(get<0>(v)<MINFRIENDSHIP)
        get<0>(v) = MINFRIENDSHIP;
} 