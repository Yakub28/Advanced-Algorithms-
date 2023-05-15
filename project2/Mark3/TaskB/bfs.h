#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    string player;
    vector<Node*> edge;
    bool visited = false;
    Node* prev = nullptr;
    int speed;
    double time = 0;

    Node(string name, string player = "No", int speed = 1)
    {
        this->speed = speed;
        this->player = player;
        this->name = name;
    }

    void add_edge(Node* node)
    {
        this->edge.push_back(node);
        node->edge.push_back(this);
    }

    string toString()
    {
        return this->name;
    }
};

class ShortestPath
{
public:
    Node* start;
    vector<Node*> players_pos;

    ShortestPath(Node* start, vector<Node*> players)
    {
        this->start = start;
        this->players_pos = players;
    }

    void bfs()
    {
        queue<Node*> queue;
        start->visited = true;
        queue.push(start);

        while (!queue.empty())
        {
            Node* current_node = queue.front();
            queue.pop();

            for (auto node : current_node->edge)
            {
                if (!node->visited)
                {
                    node->visited = true;
                    queue.push(node);
                    node->prev = current_node;
                }
            }
        }

        build_path();
    }

    void build_path()
    {
        Node* winner = players_pos[0];

        for (auto n : players_pos)
        {
            Node* node = n;
            vector<Node*> route;
            while (node != nullptr)
            {
                route.push_back(node);
                node = node->prev;
            }

            for (auto x : route)
            {
                n->time += 60 / n->speed;
            }

            winner = winner->time < n->time ? winner : n;

            cout << "Player: " << n->player << " has left labyrinth, starting from point: " << route[0]->name 
                << ", in " << n->time << " minutes, with speed " << n->speed << " seconds" << endl;

            cout << "path: ";
            for (auto x : route)
            {
                cout << x->name << " ";
            }
            cout << endl;
        }

        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Player: " << winner->player << " has won with time: " << winner->time << " minutes taken" << endl;
    }
};