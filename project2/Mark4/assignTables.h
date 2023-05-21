#ifndef ASSIGN_TABLES_H
#define ASSIGN_TABLES_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using Graph = unordered_map<string, vector<string>>;

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

#endif  // ASSIGN_TABLES_H
