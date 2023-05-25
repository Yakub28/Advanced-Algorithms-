#include <iostream>
#include <vector>
#include <cassert>

#include "RabinKarp2D.h"

using namespace std;

int main()
{
    vector<vector<int>> picture = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}};

    assert(rabin_karp(2, picture) == true);
    cout << "Passed" << endl;
    vector<vector<int>> picture1 = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}};

    assert(rabin_karp(2, picture1) == true);
    cout << "Passed" << endl;
    vector<vector<int>> picture2 = {
        {1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}};

    assert(rabin_karp(2, picture2) == true);
    cout << "Passed" << endl;
    vector<vector<int>> picture3 = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 3, 4},
        {19, 20, 21, 22, 9, 10}};

    assert(rabin_karp(2, picture3) == true);
    cout << "Passed" << endl;
    return 0;
}