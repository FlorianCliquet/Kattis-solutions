#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int INF = 1e9;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    cin.ignore();

    vector<pair<int, string>> videos;
    unordered_set<char> unique_categories;
    
    for (int i = 0; i < t; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int time;
        string categories;
        ss >> time >> categories;

        videos.push_back({time, categories});
        for (char c : categories) {
            unique_categories.insert(c);
        }
    }

    unordered_map<char, int> category_to_bit;
    int bit_position = 0;
    for (char c : unique_categories) {
        category_to_bit[c] = bit_position++;
    }

    int num_categories = unique_categories.size();
    int full_mask = (1 << num_categories) - 1;

    vector<int> dp(1 << num_categories, INF);
    dp[0] = 0;

    // Process each video
    for (auto &[time, categories] : videos) {
        int mask = 0;
        for (char c : categories) {
            mask |= (1 << category_to_bit[c]);
        }

        for (int i = full_mask; i >= 0; --i) {
            int new_mask = i | mask;
            dp[new_mask] = min(dp[new_mask], dp[i] + time);
        }
    }

    int result = dp[full_mask];

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
