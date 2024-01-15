#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computePrefixFunction(const string& pattern, vector<int>& prefix) {
    int m = pattern.size();
    prefix.resize(m);
    prefix[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }

        if (pattern[k] == pattern[q]) {
            k++;
        }

        prefix[q] = k;
    }
}

void kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> prefix;

    computePrefixFunction(pattern, prefix);

    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }

        if (pattern[q] == text[i]) {
            q++;
        }

        if (q == m) {
            int s = i - m + 1;
            cout << "Pattern found at position " << s << endl;
            q = prefix[q - 1];
        }
    }
}

int main() {
    string text = "ababcababcabcabc";
    string pattern = "ababc";

    kmpSearch(text, pattern);

    return 0;
}

