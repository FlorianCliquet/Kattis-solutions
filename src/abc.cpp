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
    vector<int> v(3);
    for(int i = 0; i < 3; i++){
        v[i] = fast_input();
    }
    sort(v.begin(), v.end());
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++){
        switch(s[i]){
            case 'A':
                cout << v[0] << " ";
                break;
            case 'B':
                cout << v[1] << " ";
                break;
            case 'C':
                cout << v[2] << " ";
                break;
        }
    }
    cout << endl;
  return 0;
}