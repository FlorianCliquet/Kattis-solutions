#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// BFS to find the shortest path
int main() {
    FAST_IO;
    
    int n, m;
    cin >> n >> m;
    
    string initial, target;
    cin >> initial >> target;
    
    unordered_set<string> lucky_numbers;
    for (int i = 0; i < m; ++i) {
        string lucky;
        cin >> lucky;
        lucky_numbers.insert(lucky);
    }

    // If target is already equal to initial, the answer is immediate
    if (initial == target) {
        cout << 0 << endl;
        cout << initial << endl;
        return 0;
    }

    // BFS setup
    queue<string> q;
    unordered_map<string, string> parent;  // To track the parent of each state (for path reconstruction)
    
    q.push(initial);
    parent[initial] = "";  // Initial state has no parent
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        // Try all possible single-step moves
        for (int i = 0; i < n; i++) {
            for (int dir : {-1, 1}) {
                string next = current;
                next[i] = (next[i] - '0' + dir + 10) % 10 + '0';  // Adjust digit cyclically
                
                if (next == target) {
                    // We've found the target, now reconstruct the path
                    vector<string> path;
                    path.push_back(target);
                    string state = current;
                    
                    while (!parent[state].empty()) {
                        path.push_back(state);
                        state = parent[state];
                    }
                    
                    path.push_back(initial);
                    reverse(path.begin(), path.end());

                    cout << path.size() - 1 << endl;
                    for (const string& s : path) {
                        cout << s << endl;
                    }
                    return 0;
                }
                
                // Only add to queue if it's a lucky number and hasn't been visited
                if (lucky_numbers.count(next) && !parent.count(next)) {
                    parent[next] = current;  // Track the parent of this state
                    q.push(next);
                }
            }
        }
    }
    
    // If no path was found, output "Neibb"
    cout << "Neibb" << endl;
    return 0;
}
