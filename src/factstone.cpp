#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimzie ("fast-math")
int main(){
  FAST_IO;
    int n,i; cin >> n;
    while(n){
        n = (n - 1960)/10 + 2;
        /**
         * extract the number of bits from a year
         */
        double m = 1<<n;
        /**
         * calculate 2^n
         */
        for(i = 1; m > 0; i++)m -= log(i) / log(2);
        /**
         * log(i) / log(2) is log2(i)
         * m is the number of bits
         * so we remove log2(i) from m until m is less than 0
         * We remove this because of this equation :
         * n! <= 2^m
         * log(n!) <= m
         * log(n) + log(n-1) + ... + log(1) <= m
         * m - log(n) - log(n-1) - ... - log(1) >= 0
         * so here n is i
         */
        cout << i - 2 << "\n"; // i - 2 because we have to remove the last one that made m < 0
        cin >> n;
    }
  return 0;
}