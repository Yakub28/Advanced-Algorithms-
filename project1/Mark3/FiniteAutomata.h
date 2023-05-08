#ifndef FINITE_AUTOMATA_H
#define FINITE_AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> finite_automata(string &pat, string &txt) {
    vector<int> matches;

    int p_len = pat.size(), t_len = txt.size();

    // Build the finite automaton
    vector<vector<int>> automaton(p_len + 1, vector<int>(256, 0));

    for (int state = 0; state <= p_len; state++) {
        for (int ch = 0; ch < 256; ch++) {        
            int next = min(p_len, state + 1);

            while (next > 0 && pat[next - 1] != ch) {
                next = automaton[next - 1][ch];
            }

            automaton[state][ch] = next;
        }
    }

    int state = 0;
    for (int i = 0; i < t_len; i++) {
        state = automaton[state][txt[i]];
        if (state == p_len) {
            matches.push_back(i - p_len + 1);
        }
    }

    return matches;
}

#endif  // FINITE_AUTOMATA_H