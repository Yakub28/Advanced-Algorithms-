#include <iostream>
#include <vector>
#include <string>

#include "BruteForceWildcard.h"
#include "SundayWildcard.h"

using namespace std;

int main(){
    string text     = "abcdefbcabcdef";
    string pattern  = "defbca";

    bool ans1 = bruteforce(pattern, text);
    bool ans2 = sunday(pattern, text);

    cout << "Brute Force: ";
    if(ans1) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "Sunday: ";
    if(ans2) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}