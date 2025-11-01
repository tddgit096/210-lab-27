//Toma Dimov | Lab-27 | COMP210

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int MAXFRIENDSHIP = 10; int MINFRIENDSHIP = 0; int TOTALSTATS = 3;

void displayVillagerStats(tuple<int,string,string>);
void displayAll(map<string, tuple<int,string,string>>);
void increaseFriendship(); //takes negative as well
void searchForVillager();

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerStats;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerStats["Audie"] = {3, "Hummingbird", "Get a load of this."};
    villagerStats["Raymond"] = {5, "Whale", "Why the hurry?"};
    villagerStats.insert({"Marshal", {7, "Ape", "What's for dinner?"}});

    // delete an element
    villagerStats.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s stats: [";
        auto[friendship, species, phrase]=it->second;
        displayVillagerStats(it->second);
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerStats.size() << endl;
    villagerStats.clear();
    cout << "Size after clear: " << villagerStats.size() << endl;

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

void searchForVillager();


void increaseFriendship(tuple<int,string,string> v, int val){//takes negative as well
    get<0>(v) += val;
    //clamp values
    if(get<0>(v)>MAXFRIENDSHIP)
        get<0>(v) = MAXFRIENDSHIP;
    else if(get<0>(v)<MINFRIENDSHIP)
        get<0>(v) = MINFRIENDSHIP;
} 

