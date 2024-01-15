#include <iostream>
#include <vector>
using namespace std;

const int MAX_STATES = 100;
const int MAX_ALPHABET = 26;

string pattern = "mair";
int transition[MAX_STATES][MAX_ALPHABET];
string alphabet = "amri";

void computeTransitionFunction();
void finiteAutomatonMatching(const string& text);
void printTransitionTable(int m, int lenAlpha) {
    cout << "Transition Function:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < lenAlpha; j++) {
             cout << transition[i][alphabet[j] - 'a'] << " ";
        }
        cout << endl;
    }
}

int main() {
    string text;

    // Prompt user for input
    cout << "Enter text: ";
    cin >> text;

    computeTransitionFunction();
    finiteAutomatonMatching(text);
    printTransitionTable(pattern.size(), alphabet.size());

    return 0;
}

void computeTransitionFunction() {
    int m = pattern.size();
    int lenAlpha = alphabet.size();

    for (int q = 0; q <= m; q++) {
        for (int j = 0; j < lenAlpha; j++) {
            int k = 1 + min(m, q + 1);

            while (k > 0) {
                k--;

                string prefix = pattern.substr(0, k);
                string suffix = pattern.substr(0, q) + alphabet[j];
                string check = suffix.substr(suffix.size() - k);

                if (prefix == check) {
                    break;
                }
            }


           transition[q][alphabet[j]-'a']  = k;
        }
    }
}

void finiteAutomatonMatching(const string& text) {
    int n = text.size();
    int m = pattern.size();
    int q = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

       q = transition[q][text[i] - 'a'];

        if (q == m) {
            int s = i - m + 1;
            cout << "Pattern occurs with shift " << s << endl;
            count++;
        }
    }

    cout << "Total matched substrings: " << count << endl;
}
