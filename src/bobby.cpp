#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define scan(x) scanf("%d", &x)
typedef long double ld;


int fact(int n) {
    if (n == 0) return 1;
    int res = 1;
    rep(i, 2, n + 1) res *= i;
    return res;
}

ld solve(int r, int s) {
    ld res = r - 1;
    return res / s;
}

ld solve(ld p, int X, int Y) {
    ld t = pow(p, Y - X);
    p = 1.0 - p;
    rep(i, 0, X) t *= p;
    int k = fact(Y) / fact(X); 
    k /= fact(Y - X);
    return t * k;
}

bool good(int R, int S, int X, int Y, int W) {
    ld p = solve(R, S);
    ld t = 0;
    for (int i = X; i <= Y; ++i) t += solve(p, i, Y);
    t *= W;
    return t > 1.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scan(T);
    while (T--) {
        int R, S, X, Y, W;
        scan(R); scan(S); scan(X);
        scan(Y); scan(W);
        cout << (good(R, S, X, Y, W) ? "yes" : "no") << endl;
    }
    return 0;
}