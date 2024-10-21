#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define nl endl
#define ll long long
/* Main()  function */
int main()
{
    ll n;

    while(cin >> n){
          if(n == 0 || n == 1) cout << 1 << nl;
          else {
              // Approximation de Stirling
              double log_factorial = n * log10(n) - n * log10(exp(1)) + log10(sqrt(2 * M_PI * n));
              ll res = floor(log_factorial) + 1;
              cout << res << endl;
          }
    }
    return 0;
}