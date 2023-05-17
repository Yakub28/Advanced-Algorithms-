#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<string, vector<string>> Graph;

void addEdge(Graph& graph, const string& u, const string& v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool assignTablesDFS(Graph& graph, const string& currentNode, unordered_map<string, int>& assignedTables,
                     unordered_set<string>& visited, int tableNumber) {
    assignedTables[currentNode] = tableNumber;
    visited.insert(currentNode);

    for (const string& neighbor : graph[currentNode]) {
        if (visited.find(neighbor) != visited.end()) {
            if (assignedTables[neighbor] == assignedTables[currentNode]) {
                return false;  // Two guests who dislike each other are assigned to the same table
            }
        } else {
            if (!assignTablesDFS(graph, neighbor, assignedTables, visited, 3 - tableNumber)) {
                return false;
            }
        }
    }

    return true;
}

bool assignTables(Graph& graph, vector<string>& guests, unordered_map<string, int>& assignedTables) {
    unordered_set<string> visited;

    for (const string& guest : guests) {
        if (visited.find(guest) == visited.end()) {
            if (!assignTablesDFS(graph, guest, assignedTables, visited, 1)) {
                return false;
            }
        }
    }

    return true;
}

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
