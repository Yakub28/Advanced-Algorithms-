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
            // Check for escape character '\'
            if(pat[j] == '\\'){
                j++;
                k++;
                if (txt[i + j - k] != pat[j]) break;
                continue;
            }
            // Handle wildcard character '?'
            if (pat[j] == '?') {
                continue;
            } 
            // Handle wildcard character '*'
            else if (pat[j] == '*') {
                // Skip consecutive '*' and '?' characters
                while (pat[j+1] == '*' || pat[j+1] == '?') {
                    j++;
                }
                // Recursive call for remaining pattern and text
                for (int y = 0; i + j + y < t_len; y++) {
                    if (bruteforce((pat.substr(j+1)), (txt.substr(i + j + y - k)))) {
                        return true;
                    }
                }
                return false;
            } 
            // Compare characters
            if (txt[i + j - k] != pat[j]) break;
        }
        // Pattern matches the text
        if (j == p_len){
            return true;
        }
    }

    return false;
}

#endif  // BRUTEFORCE_WILDCARD_H