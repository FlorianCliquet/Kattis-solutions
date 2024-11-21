#include <bits/stdc++.h>

using namespace std;

typedef struct S {
    int b;
    int s;
} S;

typedef struct SP {
    int id;
    int n;
} SP;

typedef struct P {
    long long int p;
    long long int c;
} P;

long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long int *sa, *sb, *sc;

int main(int ac, char *av[]) {
    long long int cap;
    if (scanf("%lld", &cap) != 1) return EXIT_FAILURE;

    int ns;
    if (scanf("%d", &ns) != 1) return EXIT_FAILURE;

    int np;
    if (scanf("%d", &np) != 1) return EXIT_FAILURE;

    vector<S> st;
    for (int i = 0; i < ns; ++i) {
        S s;
        if (scanf("%d%d", &s.b, &s.s) != 2) return EXIT_FAILURE;
        st.push_back(s);
    }

    vector<P> pk;
    long long int g = -1;
    for (int i = 0; i < np; ++i) {
        int nn;
        if (scanf("%d", &nn) != 1) return EXIT_FAILURE;
        P p;
        p.p = 0;
        p.c = 0;
        for (int j = 0; j < nn; ++j) {
            SP sp;
            int x;
            if (scanf("%d%d", &x, &sp.n) != 2) return EXIT_FAILURE;
            sp.id = x - 1;
            p.p += (long long int)sp.n * (st[sp.id].s - st[sp.id].b);
            p.c += (long long int)sp.n * st[sp.id].b;
        }
        if (p.p <= 0) continue;
        if (p.c > cap) continue;
        if (p.c < 0) return EXIT_FAILURE;
        pk.push_back(p);
        if (g == -1) {
            g = p.c;
        } else {
            if (p.c >= 0) g = gcd(g, p.c);
        }
    }

    if (pk.empty()) {
        printf("0\n");
        return EXIT_SUCCESS;
    }

    long long int nc = cap / g;

    sb = (long long int *)calloc(nc + 1, sizeof(long long int));
    if (sb == NULL) return EXIT_FAILURE;
    sa = (long long int *)calloc(nc + 1, sizeof(long long int));
    if (sa == NULL) return EXIT_FAILURE;

    long long int co, nc2, co2;
    for (int i = 1; i <= (int)pk.size(); ++i) {
        co = g;
        nc2 = pk[i - 1].c / g;
        for (long long int j = 1; co <= cap && j <= nc; ++j) {
            co2 = j - nc2;

            if (co < pk[i - 1].c) {
                sa[j] = sb[j];
            } else {
                if (sb[j] < sb[co2] + pk[i - 1].p) {
                    sa[j] = sb[co2] + pk[i - 1].p;
                } else {
                    sa[j] = sb[j];
                }
            }
            co += g;

            if (sa[j - 1] > sa[j]) {
                sa[j] = sa[j - 1];
            }
        }

        sc = sa;
        sa = sb;
        sb = sc;
    }

    printf("%lld\n", sb[nc]);

    return EXIT_SUCCESS;
}
