#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> preprocess(string pattern) {
    int m = pattern.length();
    vector<int> shift(256, m + 1);

    for (int i = 0; i < m; i++) {
        shift[pattern[i]] = m - i;
    }

    return shift;
}

void sunday(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> shift = preprocess(pattern);

    int i = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m && pattern[j] == text[i + j]) {
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }

        if (i + m >= n) {
            break;
        }

        i += shift[text[i + m]];
    }
}

int main() {
    string text = "hello world, how are you doing today? how";
    string pattern = "how";

    sunday(text, pattern);

    return 0;
}
