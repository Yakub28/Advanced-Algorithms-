#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> bruteforce(string &pat, string &txt){
    vector<int> matches;

    int p_len = pat.size(), t_len = txt.size();

    for (int i = 0; i <= t_len - p_len; i++) {
        int j;

        for (j = 0; j < p_len; j++){
            if (txt[i + j] != pat[j]){
                break;
            }
        }

        if (j == p_len){
            matches.push_back(i);
        }
    }

    return matches;
}

#endif  // BRUTEFORCE_H