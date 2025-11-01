//Toma Dimov | Lab-27 | COMP210

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int MAXFRIENDSHIP = 10;

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagerStats;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerStats["Audie"] = {3, "Hummingbird", "Get a load of this."};
    villagerStats["Raymond"] = {5, "Whale", "Why the hurry?"};
    villagerStats.insert({"Marshal", {7, "Ape", "What's for dinner?"}});



    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerStats) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerStats.begin(); 
                                               it != villagerStats.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerStats.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerStats.size() << endl;
    villagerStats.clear();
    cout << "Size after clear: " << villagerStats.size() << endl;

    return 0;
}