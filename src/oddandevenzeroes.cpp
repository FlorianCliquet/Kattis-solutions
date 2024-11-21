#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long p25[14], x[14];
  p25[0] = 1;
  for (int i = 1; i <= 13; i++) p25[i] = 25 * p25[i-1];
  x[0] = 1;
  for (int i = 1; i <= 13; i++) x[i] = p25[i]*2/5 + 5*x[i-1];

  long long n;
  while (cin >> n) {
    if(n==-1)
        break;
    n++;
    unsigned long long ret = 0;
    int i, j, parity = 0;
    for (i = 13; i >= 0; i--) {
      for (j = 0; p25[i] <= n; j++, n -= p25[i]) {
        ret += (parity ^ (j%10 <= 4)) ? x[i] : p25[i] - x[i];
      }
      parity ^= (j%10 > 4);
    }
    cout << ret << endl;
  }
  return 0;
}