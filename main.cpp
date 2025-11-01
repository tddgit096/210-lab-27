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
tuple<int,string,string> searchForVillager();


int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerStats;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerStats["Audie"] = {3, "Hummingbird", "Get a load of this."};
    villagerStats["Raymond"] = {5, "Whale", "Why the hurry?"};
    villagerStats.insert({"Marshal", {7, "Ape", "What's for dinner?"}});

    //Menu:
    while(true){
        int input;
        cout<<"1. Increase Friendship\n";
        cout<<"2. Decrease Friendship\n";
        cout<<"3. Search for Villager\n";
        cout<<"4. Exit\n";
        cin>>input
    }

/*
    // delete an element
    villagerStats.erase("Raymond");

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerStats.size() << endl;
    villagerStats.clear();
    cout << "Size after clear: " << villagerStats.size() << endl;
*/
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

tuple<int,string,string> searchForVillager(map<string, tuple<int,string,string>> m,string key){
    auto it = m.find(key);
    if (it != m.end()) {  // the iterator points to beyond the end of the map if key is not found
        return it->second;
    } else
        cout << endl << key << " not found." << endl;
}

void increaseFriendship(tuple<int,string,string> &v, int val){//takes negative as well
    get<0>(v) += val;
    //clamp values
    if(get<0>(v)>MAXFRIENDSHIP)
        get<0>(v) = MAXFRIENDSHIP;
    else if(get<0>(v)<MINFRIENDSHIP)
        get<0>(v) = MINFRIENDSHIP;
} 