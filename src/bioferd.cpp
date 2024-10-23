#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = 2147483647;

// Graph adjacency list, visited flag for each node, and owner of each node
vector<vi> adj;   // adjacency list to store the graph
vector<bool> done; // visited array for alternating path search
vector<int> owner; // owner array for matching

// Function to find an alternating path in the bipartite graph
bool alternating_path(int left) {
    if (done[left]) return false;
    done[left] = true;

    // Traverse through all the nodes on the right that are connected to 'left'
    for (int right : adj[left]) {
        // If the right node is unmatched or we can find an augmenting path
        if (owner[right] == -1 || alternating_path(owner[right])) {
            owner[right] = left;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n; // number of nodes on the left side of the bipartite graph

    adj.resize(n);    // resize adjacency list
    done.resize(n);   // resize visited array
    owner.assign(n, -1); // initialize owner array with -1 (indicating unmatched nodes)

    // Read the bipartite graph
    for (int i = 0; i < n; ++i) {
        int cnt;
        cin >> cnt; // number of nodes on the right side connected to node i
        for (int j = 0; j < cnt; ++j) {
            int x;
            cin >> x;
            adj[i].push_back(x - 1); // store 0-based index for the right side nodes
        }
    }

    int match_count = 0;
    
    // Try to find a matching for each node on the left side
    for (int i = 0; i < n; ++i) {
        fill(done.begin(), done.end(), false); // reset visited array for each new node
        if (alternating_path(i)) {
            ++match_count;
        }
    }

    // If not all nodes could be matched, print "Neibb" and exit
    if (match_count < n) {
        cout << "Neibb" << endl;
        return 0;
    }

    // Otherwise, print the owner of each node on the right side (1-based index)
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " "; // add a space between outputs
        cout << owner[i] + 1;   // convert to 1-based index
    }
    cout << endl;

    return 0;
}