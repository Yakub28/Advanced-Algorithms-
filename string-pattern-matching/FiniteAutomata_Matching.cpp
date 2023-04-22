#include <iostream>
#include <vector>
#include <string>

using namespace std;

void matchAutomaton(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    // Build the finite automaton
    vector<vector<int>> automaton(m + 1, vector<int>(256, 0));
    for (int state = 0; state <= m; state++) {
        for (int ch = 0; ch < 256; ch++) {
            
            int next = min(m, state + 1);
            while (next > 0 && pattern[next - 1] != ch) {
                next = automaton[next - 1][ch];
            }
            automaton[state][ch] = next;
        }
    }

    vector<int> matches;
    int state = 0;
    for (int i = 0; i < n; i++) {
        state = automaton[state][text[i]];
        if (state == m) {
            cout<<"Match is found: "<<i - m + 1<<"\n";
        }
    }
}

int main() {
    string p="aaa";
    string txt="baaabaaaba";
    matchAutomaton(txt, p);
    
    return 0;
}