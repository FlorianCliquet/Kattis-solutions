#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int power(int a, int n, int MOD) {
    int res = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) {
            res = 1LL * res * a % MOD;
        }
    }
    return res;
}

int inverse(int a, int MOD) {
    return power(a, MOD - 2, MOD);
}

typedef pair<int, int> i2;
i2 fact[2000010];

int nCk(int n, int k, int m) {
    if (k > n) return 0;
    i2 TS = fact[n];
    i2 MS = i2(1LL * fact[k].first * fact[n - k].first % m, fact[k].second + fact[n - k].second);
    int res = 1LL * TS.first * inverse(MS.first, m) % m;
    if (TS.second > MS.second) return 0;
    return res;
}

void sol() {
    int n, m;
    cin >> n >> m;

    fact[0] = {1, 0};
    for (int i = 1; i <= n; i++) {
        int mu = 0;
        int j = i;
        while (j % m == 0) {
            mu++;
            j /= m;
        }
        fact[i] = {1LL * fact[i - 1].first * j % m, fact[i - 1].second + mu};
    }

    int f0 = 1, f1 = 2;
    for (int i = 2; i <= n; i++) {
        int f2 = (f0 + f1) % m;
        f0 = f1;
        f1 = f2;
    }

    int res = f1;
    if (n % 2 == 0 && n > 2) {
        res = (res + nCk(n, n / 2, m)) % m;
        int cost = nCk(n - n / 2 + 1, n / 2, m);
        res = (res - cost + m) % m;
    }
    
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) sol();
}
