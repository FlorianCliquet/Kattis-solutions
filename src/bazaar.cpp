#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar()
inline int fast_input() {
    int x = 0;
    char c;

    // Skip non-numeric characters, check for EOF
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

int main(){
    FAST_IO;
    int N = fast_input(); // 2N
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)A[i] = fast_input(); // Each goods for each player

    vector<int> V(N, 0); // Track of which player has which goods
    int Z = 0, W = 0; // 

    for (int i = 0; i < N; i++) {
        bool t = i < N / 2;
        V[A[i] - 1] = 1 - t; // 1 - t is to switch between 0 and 1 , 0 for player 1 and 1 for player 2
        Z += (2 * t - 1) * A[i] + i * t; // (2 * t - 1) is to switch between 1 and -1, to add or subtract the value of A[i]
        // A[i] + i *t , i * t is to add or subtract the value of i
    }

    for (int i = 0; i < N; i++) {
        Z += (V[i] == 0) ? -W : 0;
        W += V[i];
    }

    cout << Z << "\n";

    return 0;
}
