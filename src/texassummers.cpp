#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[2502];
ii points[2502];
int pred[2502];
ll est[2502];

int get_dist(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) 
        + (a.second - b.second) * (a.second - b.second);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) { 
        int u, v;
        cin >> u >> v;
        points[i] = {u, v}; 
    }
    N += 2;
    cin >> points[N - 2].first >> points[N - 2].second;
    cin >> points[N - 1].first >> points[N - 1].second;

    // Build the graph
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int d = get_dist(points[i], points[j]);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }

    fill(est, est + N, INT_MAX);
    est[N - 1] = 0; 
    pq.push({0, N - 1});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int dist = front.first, u = front.second;

        if (dist > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {
                pred[v] = u;
                est[v] = est[u] + w;
                pq.push({est[v], v});
            }
        }
    }

    if (est[N - 2] == get_dist(points[N - 2], points[N - 1])) {
        cout << "-" << endl;
        return 0;
    }

    int x = pred[N - 2];
    while (x != N - 1) {
        cout << x << endl;
        x = pred[x];
    }
}   