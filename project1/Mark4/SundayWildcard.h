#ifndef SUNDAY_WILDCARD_H
#define SUNDAY_WILDCARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> preprocess(string &pat) {
    int p_len = pat.length();

    vector<int> shift(256, p_len + 1);

    for (int i = 0; i < p_len; i++) {
        shift[pat[i]] = p_len - i;
    }

    return shift;
}

bool sunday(string &pat, string &txt) {
    int p_len = pat.length(), t_len = txt.length();

    vector<int> shift = preprocess(pat);

    int i = 0;
    while (i <= t_len - p_len) {
        int j = 0, k = 0;
        bool check = true;

        while (j < p_len) {
            if(pat[j] == '\\'){
                check = false;
                j++;
                continue;
            }
            if(check == true){
                if(pat[j] == '?'){
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

        if (j == p_len) {
            return true;
        }

        if (i + p_len >= t_len) {
            break;
        }

        i += shift[txt[i + p_len]];
    }

    return false;
}

#endif  // SUNDAY_WILDCARD_H