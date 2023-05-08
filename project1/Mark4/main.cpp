#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "BruteForceWildcard.h"
#include "SundayWildcard.h"

using namespace std;

int main(){
    string text     = "helllllo world";
    string pattern  = "he*lo";

    bool ans1 = bruteforce(pattern, text);
    bool ans2 = sunday(pattern, text);

    cout << "Brute Force: ";
    if(ans1) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "Sunday: ";
    if(ans2) cout << "True" << endl;
    else cout << "False" << endl;
    
    string pattern4 = "he*lo", text4 = "helllllo world";
    assert(bruteforce(pattern4, text4) == true);


    string pattern6 = "he*llo", text6 = "hello world";
    assert(bruteforce(pattern6, text6) == true);


    string pattern9 = "he*llo", text9 = "helloo world";
    assert(bruteforce(pattern9, text9) == true);

    return 0;
}