#include <bits/stdc++.h>
using namespace std;
#define ITER 10 

main() {
  string f[ITER+1];
  for (int i = 1; i <= ITER; i++) {
    f[i] = f[i-1] + 'L';
    for (int j = f[i-1].size()-1; j >= 0; j--)
      f[i] += (f[i-1][j] == 'L' ? 'R' : 'L');
  }

  int T, prob=1;
  for (cin >> T; T--;) {
    int N;
    string s;
    cin >> N >> s;
    cout << "Case " << prob++ << ": ";
    cout << (f[min(N, ITER)].find(s) == -1 ? "No" : "Yes") << endl;
  }
}