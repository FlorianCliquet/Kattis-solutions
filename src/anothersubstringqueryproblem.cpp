#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

int main() {
    FAST_IO
    string s;
    cin >> s; // Input the main string

    int q; // Number of queries
    cin >> q;

    unordered_map<string, vector<int>> substring_positions; // Cache positions for each substring
    vector<pair<string, int>> queries; // Store queries for later processing

    while (q--) {
        string t;
        int k;
        cin >> t >> k;
        queries.emplace_back(t, k);

        // If this substring hasn't been precomputed, process it
        if (substring_positions.find(t) == substring_positions.end()) {
            vector<int> positions;
            size_t start = 0;
            while ((start = s.find(t, start)) != string::npos) {
                positions.push_back(start + 1); // Store 1-based index
                start++;
            }
            substring_positions[t] = positions;
        }
    }

    // Process queries using precomputed positions
    for (auto& query : queries) {
        string t = query.first;
        int k = query.second;
        const vector<int>& positions = substring_positions[t];

        if (positions.size() < k) {
            cout << -1 << endl; // Not enough occurrences
        } else {
            cout << positions[k - 1] << endl; // k-th occurrence (1-based index)
        }
    }

    return 0;
}