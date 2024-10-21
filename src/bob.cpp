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

struct col{
    int val = 0;
    int64_t A;
    vector<pair<int,int>> S;
    void add(int v,int w){
        if(v != val){
            val = v;
            S.clear();
            A = 0;
        }
        int h = 1;
        while(!S.empty() && S.back().first >= w){
            auto [sw,sh] = S.back();
            S.pop_back();
            A -= sw*sh;
            h += sh;
        }
        S.emplace_back(w,h);
        A += w*h;
    }
};
vector<vector<int>> R;
vector<vector<int>> A;

int main(){
  FAST_IO;
    int n = fast_input(), m = fast_input();
    R.resize(n, vector<int>(m));
    for(auto&row : R){
        for(auto&x : row){
            x = fast_input();
        }
    }
    A.resize(n, vector<int>(m,1));
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(R[i][j] == R[i][j-1])
                A[i][j] = A[i][j-1] + 1;
        }
    }
    vector<col> C(m);
    int64_t ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            C[j].add(R[i][j],A[i][j]);
            ans += C[j].A;
        }
    }
    cout << ans << endl;
  return 0;
}