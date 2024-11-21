#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
const int NN = 505;

int cases;
int n, m, adj[NN][NN], deg[NN], d[NN], pr[NN];

int bfs(int s) {
  queue<int> q;
  int res = INF;

  for (int i = 0; i < n; i++) d[i] = INF;
  d[s] = 0;
  pr[s] = -1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < deg[u]; i++) {
      int v = adj[u][i];
      if (v != pr[u]) {
        if (d[v] == INF) {
          d[v] = d[u] + 1;
          pr[v] = u;
          q.push(v);
        } else {
          res = min(res, d[v] + d[u] + 1);
          if (res == 3) return 3;
        }
      }
    }
  }
  return res;
}

int main() {
  cases = 1;
  while (cases--) {
    scanf("%d %d", &n, &m);
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u][deg[u]++] = v;
      adj[v][deg[v]++] = u;
    }
    int res = INF;
    for (int u = 0; u < n && res != 3; u++) res = min(res, bfs(u));
    if (res == INF) puts("impossible");
    else printf("%d\n", res);
  }
  return 0;
}
