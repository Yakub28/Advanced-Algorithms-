#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "assignTables.h"
using namespace std;



int main() {
    Graph graph;
    vector<string> guests = {"Alice", "Bob", "Charlie", "Dave", "Mark"};
    vector<pair<string, string>> dislikes = {{"Alice", "Bob"}, {"Charlie", "Dave"}, {"Mark", "Dave"}, {"Alice", "Mark" }};

    for (const auto& pair : dislikes) {
        addEdge(graph, pair.first, pair.second);
    }

    unordered_map<string, int> assignedTables;

    if (assignTables(graph, guests, assignedTables)) {
        // Print the assigned tables
        for (const string& guest : guests) {
            cout << guest << " assigned to table " << assignedTables[guest] << endl;
        }
    } else {
        cout << "No valid sitting arrangement possible." << endl;
    }

    return 0;
}
