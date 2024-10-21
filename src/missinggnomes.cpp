#include <bits/stdc++.h>
using namespace std;
#define N 100005
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

int n,m,a[N],b[N],c[N],cnt;
int main(){
    
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> a[i], b[a[i]]=1;
    a[m+1]=n+1;
    int pos=1;
    for(int i=1;i<=n+1;i++)
    if(!b[i]){
        while(a[pos]<i){
            c[++cnt]=a[pos++];
        }
        c[++cnt]=i;
    }
    for(int i=1;i<=n;i++) cout << c[i] << "\n";
    return 0;
}