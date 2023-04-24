#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> rabin_karp(string &pat, string &txt){
    vector<int> matches;

    int p_len = pat.size(), t_len = txt.size();

    int S = 127, L = 997;

    int hP = 0, hT = 0;
    for(int i = 0; i < p_len; i++){
        hP = ((hP * S) % L + pat[i]) % L;
        hT = ((hT * S) % L + txt[i]) % L;
    }

    if(hP == hT) matches.push_back(0);

    int spow = 1;
    for(int i = 1; i < p_len; i++) spow = (spow * S) % L;

    for(int i = 1; i <= t_len - p_len; i++){
        hT = (hT - (txt[i - 1] * spow % L) + L) % L;
        hT = ((hT * S) % L + txt[i + p_len - 1]) % L;
        
        if(hP == hT) matches.push_back(i);
    }

    return matches;
}

#endif  // RABIN_KARP_H