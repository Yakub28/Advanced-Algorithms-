#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "BruteForceWildcard.h"
#include "SundayWildcard.h"

using namespace std;

int main()
{
    string pattern0 = "he\\*lo", text0 = "he*lo world";
    assert(sunday(pattern0, text0) == true);
    assert(bruteforce(pattern0, text0) == true);
    cout << "Passed 0" << endl;

    string pattern1 = "he*lo", text1 = "helllllo world";
    assert(sunday(pattern1, text1) == true);
    assert(bruteforce(pattern1, text1) == true);
    cout << "Passed 1" << endl;

    string pattern2 = "he*llo", text2 = "hello world";
    assert(sunday(pattern2, text2) == true);
    assert(bruteforce(pattern2, text2) == true);
    cout << "Passed 2" << endl;

    string pattern3 = "e\\*?", text3 = "he*lloo world";
    assert(sunday(pattern3, text3) == true);
    assert(bruteforce(pattern3, text3) == true);
    cout << "Passed 3" << endl;

    string pattern4 = "e\\**", text4 = "he*lloo world";
    assert(sunday(pattern4, text4) == true);
    assert(bruteforce(pattern4, text4) == true);
    cout << "Passed 4" << endl;

    string pattern5 = "e\\*\\*", text5 = "he*lloo world";
    assert(sunday(pattern5, text5) == false);
    assert(bruteforce(pattern5, text5) == false);
    cout << "Passed 5" << endl;

    string pattern6 = "e\\*?*", text6 = "he*lloo world";
    assert(sunday(pattern6, text6) == true);
    assert(bruteforce(pattern6, text6) == true);
    cout << "Passed 6" << endl;

    string pattern7 = "e\\*", text7 = "he*lloo world";
    assert(sunday(pattern7, text7) == true);
    assert(bruteforce(pattern7, text7) == true);
    cout << "Passed 7" << endl;

    string pattern8 = "e\\*?*w", text8 = "he*lloo world";
    assert(sunday(pattern8, text8) == true);
    assert(bruteforce(pattern8, text8) == true);
    cout << "Passed 8" << endl;

    string pattern9 = "e\\**w", text9 = "he*lloo world";
    assert(sunday(pattern9, text9) == true);
    assert(bruteforce(pattern9, text9) == true);
    cout << "Passed 9" << endl;

    return 0;
}