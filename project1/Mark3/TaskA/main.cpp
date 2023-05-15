#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
#include <iostream>
#include <vector>
#include <string>

#include "BruteForce.h"
#include "Sunday.h"
#include "KMP.h"
#include "FiniteAutomata.h"
#include "RabinKarp.h"
#include "GusfieldZ.h"

using std::chrono::nanoseconds;

constexpr int step = 10;
constexpr int maxlen = 100;
constexpr int times = 10;

nanoseconds timeit(string &pat, string &txt, vector<int> what(string &, string &)) {
    auto begin = std::chrono::steady_clock::now();
    what(pat, txt);
    auto end = std::chrono::steady_clock::now();

    nanoseconds total(end - begin);
    return total;
}

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

    std::cout
        << "Brute" << " | "
        << "Sunday" << " | "
        << "KMP" << " | "
        << "FMS" << " | "
        << "Rabin Karp" << " | "
        << "Gusfield Z" << std::endl;

    nanoseconds bruteforce_time(0);
    nanoseconds sunday_time(0);
    nanoseconds kmp_time(0);
    nanoseconds finite_automata_time(0);
    nanoseconds rabin_karp_time(0);
    nanoseconds gusfield_z_time(0);

    for (int t = 0 ; t < times ; t++) {
        bruteforce_time += timeit(pattern, text, &bruteforce);
        sunday_time += timeit(pattern, text, &sunday);
        kmp_time += timeit(pattern, text, &kmp);
        finite_automata_time += timeit(pattern, text, &finite_automata);
        rabin_karp_time += timeit(pattern, text, &rabin_karp);
        gusfield_z_time += timeit(pattern, text, &gusfield_z);
    }

    std::cout
        << bruteforce_time.count() / times << " | "
        << sunday_time.count() / times << " | "
        << kmp_time.count() / times << " | "
        << finite_automata_time.count() / times << " | "
        << rabin_karp_time.count() / times << " | "
        << gusfield_z_time.count() / times << std::endl;


    // printResult("Brute Force", pattern, text, &bruteforce);
    // printResult("Sunday", pattern, text, &sunday);
    // printResult("KMP", pattern, text, &kmp);
    // printResult("Finite Automata", pattern, text, &finite_automata);
    // printResult("Rabin Karp", pattern, text, &rabin_karp);
    // printResult("Gusfield Z", pattern, text, &gusfield_z);

    return 0;
}