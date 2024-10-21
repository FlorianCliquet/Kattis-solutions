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
    int n = fast_input();
    switch(n){
        case 1: cout << "31"; break;
        case 2: cout << "28"; break;
        case 3: cout << "31"; break;
        case 4: cout << "30"; break;
        case 5: cout << "31"; break;
        case 6: cout << "30"; break;
        case 7: cout << "31"; break;
        case 8: cout << "31"; break;
        case 9: cout << "30"; break;
        case 10: cout << "31"; break;
        case 11: cout << "30"; break;
        case 12: cout << "31"; break;
    }
  return 0;
}