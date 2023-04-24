#include <iostream>
#include <vector>
#include <string>

#include "BruteForce.h"
#include "Sunday.h"
#include "KMP.h"
#include "FiniteAutomata.h"
#include "RabinKarp.h"
#include "GusfieldZ.h"

using namespace std;

void printResult(string name, string &pat, string &txt, vector<int> what(string &, string &)){
    cout << name << " : ";
    vector<int> result = what(pat, txt);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(){
    string text     = "shdjdkjskabcjaikdaajdkjabckaslkdossabc";
    string pattern  = "abc";

    printResult("Brute Force", pattern, text, &bruteforce);
    printResult("Sunday", pattern, text, &sunday);
    printResult("KMP", pattern, text, &kmp);
    printResult("Finite Automata", pattern, text, &finite_automata);
    printResult("Rabin Karp", pattern, text, &rabin_karp);
    printResult("Gusfield Z", pattern, text, &gusfield_z);

    return 0;
}