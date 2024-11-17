#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N) {
            p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
            rank.assign(N, 0);
            setSize.assign(N, 1);
            numSets = N;
        }

        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        int numDisjointSets() { return numSets; }

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
            setSize[y] += setSize[x];
            --numSets;
        }
};

void solve(int tc) {
    ll a, b, p;
    cin >> a >> b >> p;

    UnionFind UF(b - a + 1);
    for (auto v : primes) {
        if (v < p) {
            continue;
        }
        for (ll i = (a / v) * v; i <= b; i += v) {
            if (i >= a && (i - v) >= a && i <= b) {
                // cout << i << " " << (i - v) << endl;
                UF.unionSet(i - a, i - v - a);
            }
        }
    }
    cout << "Case #" << tc << ": " << UF.numDisjointSets() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(1000000);
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
    }
}