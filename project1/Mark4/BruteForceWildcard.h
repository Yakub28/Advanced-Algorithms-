#ifndef BRUTEFORCE_WILDCARD_H
#define BRUTEFORCE_WILDCARD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool bruteforce(string pat, string txt){
    int p_len = pat.size(), t_len = txt.size();

    for (int i = 0; i <= t_len - p_len; i++) {
        int j;
        bool check = true;

        for (j = 0; j < p_len; j++){
            if(pat[j] == '\\'){
                check = false;
                j++;
                continue;
            }
            if (check == true){
                if (pat[j] == '?') {
                    continue;
                } 
                else if (pat[j] == '*') {
                    while (pat[j+1] == '*' || pat[j+1] == '?') {
                        j++;
                    }
                    for (int k = 0; i + j + k < t_len; k++) {
                        if (bruteforce((pat.substr(j+1)), (txt.substr(i+j+k)))) {
                            return true;
                        }
                    }
                    return false;
                } 
            } 
            else if (txt[i + j] != pat[j]){
                break;
            }
        }

        if (j == p_len){
            return true;
        }
    }

    return false;
}

#endif  // BRUTEFORCE_WILDCARD_H