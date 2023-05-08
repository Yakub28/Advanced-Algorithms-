#ifndef BRUTEFORCE_WILDCARD_H
#define BRUTEFORCE_WILDCARD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool bruteforce(string &pat, string &txt){
    int p_len = pat.size(), t_len = txt.size();

    int i = 0;

    for (int i = 0; i <= t_len - p_len; i++) {
        int j = 0, k = 0;
        bool check = true;

        while(j < p_len){
            if(pat[j] == '\\'){
                check = false;
                j++;
                continue;
            }
            if(check == true){
                if(pat[j] == '.'){
                    j++;
                    continue;
                }
                if(pat[j] == '*'){
                    if(j == p_len - 1){
                        return true;
                    }
                    while(txt[i + j + k] != pat[j + 1]){
                        k++;
                        if(i + j + k >= t_len){
                            return false;
                        }
                    }
                    j++;
                    continue;
                }
            }
            if (txt[i + j + k] != pat[j]) break;
            j++;
        }
    }
    return false;
}

#endif  // BRUTEFORCE_WILDCARD_H