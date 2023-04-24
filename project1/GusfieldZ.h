#ifndef GUSFIELD_Z_H
#define GUSFIELD_Z_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> gusfield_z(string &pat, string &txt){
    vector<int> matches;

    int p_len = pat.size(), t_len = txt.size();

    string new_str = pat + "#" + txt;

    vector<int> Z;

    int i = 0;
    for(int i = 0; i < new_str.size(); i++){
        if(i <= p_len){
            Z.push_back(0);
            continue;
        }

        int left = 0, right = 0;

        if(new_str[left] == new_str[i]){
            right = i;
            while(right < new_str.size() && new_str[left] == new_str[right]){
                left++;
                right++;
            }
        }

        Z.push_back(left);
    }

    for(int i = 0; i < new_str.size(); i++)
        if(Z[i] == p_len)
            matches.push_back(i - p_len - 1);

    return matches;
}

#endif  // GUSFIELD_Z_H