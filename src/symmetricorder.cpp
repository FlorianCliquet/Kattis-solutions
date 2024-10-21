#include <bits/stdc++.h>
using namespace std;
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
  int n = fast_input();
  int iterator = 1;
    while(n > 0){
        if (iterator > 1) cout << endl;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            int j = (i % 2 == 0) ? (i / 2) : n - (i / 2) - 1;
            cin >> v[j];
        }
        cout << "SET " << iterator << endl;
        for(int i = 0; i < n; i++){
            if (i == n - 1) cout << v[i];
            else cout << v[i] << endl;
        }
        n = fast_input();
        iterator++;
    }
  return 0;
}