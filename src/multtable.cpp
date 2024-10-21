#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// Optimization pragmas
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")

// Fast input function to quickly read integers using getchar()
inline long long fast_input() {
    long long x = 0;
    char c;

    // Skip non-numeric characters
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

long long countOccurrences(long long n, long long x) {
    long long count = 0;
    long long limit = sqrt(x); // Calculate the integer square root of x

    // Iterate up to the integer square root of x
    for (long long i = 1; i <= limit; i++) {
        if (x % i == 0) { // Check if i is a divisor of x
            long long j = x / i; // Calculate the corresponding j
            // Check if both i and j are within bounds
            if (i <= n && j <= n) {
                count += (i == j) ? 1 : 2; // Count pairs, avoid double counting
            }
        }
    }
    return count;
}

int main() {
    FAST_IO
    long long n = fast_input(), x = fast_input();
    cout << countOccurrences(n, x) << endl; // Output result
    return 0;
}
