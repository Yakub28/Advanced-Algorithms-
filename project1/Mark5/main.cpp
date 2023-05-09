#include <iostream>
#include <vector>
#include <cassert>

#include "RabinKarp2D.h"

using namespace std;

int main(){
    vector<vector<int>> picture = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    assert(rabin_karp(2, picture) == true);

    vector<vector<int>> picture1 = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    assert(rabin_karp(2, picture1) == false);

    vector<vector<int>> picture2 = {
        {1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    assert(rabin_karp(2, picture2) == true);

    return 0;
}