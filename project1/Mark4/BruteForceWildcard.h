#ifndef BRUTEFORCE_WILDCARD_H
#define BRUTEFORCE_WILDCARD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool bruteforce(string pat, string txt){
    int p_len = pat.size(), t_len = txt.size();

    for (int i = 0; i <= t_len - p_len; i++) {
        int j, k = 0;

        for (j = 0; j < p_len; j++){
            if(pat[j] == '\\'){
                j++;
                k++;
                if (txt[i + j - k] != pat[j]) break;
                continue;
            }
            if (pat[j] == '?') {
                continue;
            } 
            else if (pat[j] == '*') {
                while (pat[j+1] == '*' || pat[j+1] == '?') {
                    j++;
                }
                for (int y = 0; i + j + y < t_len; y++) {
                    if (bruteforce((pat.substr(j+1)), (txt.substr(i + j + y - k)))) {
                        return true;
                    }
                }
                return false;
            } 

            if (txt[i + j - k] != pat[j]) break;
        }

        if (j == p_len){
            return true;
        }
    }

    return false;
}

#endif  // BRUTEFORCE_WILDCARD_H