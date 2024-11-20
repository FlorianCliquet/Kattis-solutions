#include <bits/stdc++.h>

using namespace std;

int main() {
    string pattern, text;

    while (getline(cin, pattern) && getline(cin, text)) {
        vector<int> positions;
        size_t pos = text.find(pattern);

        while (pos != string::npos) {
            positions.push_back(pos);
            pos = text.find(pattern, pos + 1);
        }

        for (size_t i = 0; i < positions.size(); i++) {
            if (i > 0) cout << " ";
            cout << positions[i];
        }
        cout << "\n";
    }

    return 0;
}