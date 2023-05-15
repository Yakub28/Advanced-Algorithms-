#include <iostream>
#include "bfs.h"

int main()
{
    // Create the nodes
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* e = new Node("E");
    Node* f = new Node("F");

    // Add the edges
    a->add_edge(b);
    a->add_edge(d);
    b->add_edge(c);
    b->add_edge(e);
    c->add_edge(f);
    d->add_edge(e);
    e->add_edge(f);

    // Create a vector of player nodes
    vector<Node*> players = {b, c};

    // Create a ShortestPath object and run the BFS algorithm
    ShortestPath sp(a, players);
    sp.bfs();

    // Clean up memory
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;

    return 0;
}

