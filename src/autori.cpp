#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    stringstream ss(input);
    string segment;
    vector<string> result;

    while (getline(ss, segment, '-')) {
        result.push_back(segment);
    }

    for (const string& part : result) {
        cout << part[0];
    }

    return 0;
}