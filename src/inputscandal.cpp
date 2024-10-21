#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
int main() {
    FAST_IO
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        lines.push_back(line);
    }

    cout << lines.size() << '\n';
    for (const auto& l : lines) {
        cout << l << '\n';
    }

    return 0;
}