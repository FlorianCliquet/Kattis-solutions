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
    map<int, int>m;
    int v[9];
    int target = 0;
    int i = 0;
    int n;
    for(int i = 0; i < 9; i++){    
        n = fast_input();    
        target += n;
        v[i] = n;
    }
    target -= 100;
    int ans[2];
    for(int i = 0; i < 9; i++){
        int complement = target - v[i];
        if(m.find(complement) != m.end()){
            ans[0] = v[i];
            ans[1] = complement;
            break;
        }
        m[v[i]]++;
    }
    for(int i = 0; i < 9; i++){
        if(v[i] != ans[0] && v[i] != ans[1]){
            cout << v[i] << endl;
        }
    }
  return 0;
}