#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
const int MAXN = 50*50*2;
int cap[MAXN][MAXN];
int nedge[MAXN];
int edge[MAXN][MAXN];
int prev[MAXN];

void addedge(int a, int b, int c) {
    edge[a][nedge[a]++] = b;
    cap[a][b] = c;
}

int maxFlowDinic(int s, int t) {
    int q[MAXN];
    int prev[MAXN];
    int flow = 0;
    int qf, qb, bot, u, v;

    while (true) {
        qf = qb = 0;
        memset(prev, -1, sizeof(prev));

        q[qb++] = s;
        prev[s] = -2;

        while (qb > qf && prev[t] == -1) {
            u = q[qf++];
            for (int i = 0; i < nedge[u]; i++)
                if (prev[v = edge[u][i]] == -1 && cap[u][v])
                    prev[q[qb++] = v] = u;
        }

        if (prev[t] == -1) return flow;

        for (int z = 0; z < n; z++)
            if (cap[z][t] && prev[z] != -1) {
                bot = cap[z][t];

                for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    bot = min(bot , cap[u][v]);

                if (!bot) continue;
                cap[z][t] -= bot;
                cap[t][z] += bot;

                for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    cap[u][v] -= bot , cap[v][u] += bot;
                flow += bot;
            }
    }
}

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    int extra = __gcd(a,b);
    a /= extra;
    b /= extra;

    vector<vector<char>> field(n, vector<char>(m));
    for(auto& i : field) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    int s = n*m;
    int t = n*m + 1;

    ::n = n*m+2;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            int curr = (i*m)+j;
            if(i > 0) {
                // join
                int prev = ((i-1)*m)+j;
                addedge(curr,prev,a);
                addedge(prev,curr,a);
            }
            if(j > 0) {
                // join
                int prev = (i*m)+j-1;
                addedge(curr,prev,a);
                addedge(prev,curr,a);
            }
            if(field[i][j] == '#') {
                // source
                addedge(s,curr,b);
            }
            else {
                // sink
                addedge(curr,t,b);
            }
        }
    }

    cout << maxFlowDinic(s,t) * (ll)extra << endl;
}