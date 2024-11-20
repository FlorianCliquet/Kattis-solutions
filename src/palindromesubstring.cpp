#include <bits/stdc++.h>

using namespace std;

#define nl "\n"

int N;
set<string> res;

void check(string s, int i, int j) {
    while (i >= 0 && j < N && s[i] == s[j]) {
        if(j-i+1 >= 2) res.insert(s.substr(i, j - i + 1));
        i--;
        j++;
    }
}

int main() {
    string s;

    while (cin >> s) {
        res.clear(); // Clear the global result vector
        N = s.size();
        for (int i = 0; i < N; i++) {
            check(s, i, i + 1); // Check for even-length palindromes
            check(s, i, i);     // Check for odd-length palindromes
        }

        for (auto& el : res) {
            cout << el << nl;
        }
    }

    return 0;
}