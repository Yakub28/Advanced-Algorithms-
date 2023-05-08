#include <iostream>
#include <vector>
#include <string>

#include "BruteForceWildcard.h"

using namespace std;

int main(){
    string text     = "abcdefbcabcdef";
    string pattern  = "a*";

    bool ans = bruteforce(pattern, text);

    if(ans) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}