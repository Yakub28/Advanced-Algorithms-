#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> kmp(string &pat, string &txt){
    vector<int> matches;

    int p_len = pat.size(), t_len = txt.size();

    // The Longest Proper Prefix
    vector<int> lps(p_len, 0);

    for(int i = 1; i < p_len; i++){
        int j = lps[i-1];
        
        while(j > 0 && pat[j] != pat[i]){
            j = lps[j-1];
        }

        if(pat[j] == pat[i]) j++;

        lps[i] = j;
    }

    int i = 0, j = 0;
    
    while(i < t_len){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }

        if(j == p_len){
            matches.push_back(i - p_len);
            j = lps[j-1];
        }
        else if(i < t_len && pat[j] != txt[i]){
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }

    return matches;
}

#endif  // KMP_H