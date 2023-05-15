#ifndef SUNDAY_H
#define SUNDAY_H

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

vector<int> sunday(string &pat, string &txt) {
    vector<int> matches;

    int p_len = pat.length(), t_len = txt.length();

    vector<int> shift = preprocess(pat);

    int i = 0;
    while (i <= t_len - p_len) {
        int j = 0;

        while (j < p_len && pat[j] == txt[i + j]) {
            j++;
        }

        if (j == p_len) {
            matches.push_back(i);
        }

        if (i + p_len >= t_len) {
            break;
        }

        i += shift[txt[i + p_len]];
    }

    return matches;
}

#endif  // SUNDAY_H