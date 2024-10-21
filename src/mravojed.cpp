#include <bits/stdc++.h>
using namespace std;

bitset<101> g[101]; 
short n, m, fr, fc, sr, sc, fs, ss;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            g[i][j] = (c == 'x');
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (g[i][j]) {
            int ii = i, jj = j;
            while (ii <= n && g[ii][j]) ii++;
            while (jj <= m && g[i][jj]) jj++;
            fs = min(ii - i, jj - j); fr = i; fc = j; goto first_found;
        }

first_found:
    cout << fr << " " << fc << " " << fs << "\n";

    for (int i = fr; i < fr + fs; i++)
        for (int j = fc; j < fc + fs; j++)
            g[i][j] = 0;

    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--) if (g[i][j]) {
            int ii = i, jj = j;
            while (ii > 0 && g[ii][j]) ii--;
            while (jj > 0 && g[i][jj]) jj--;
            ss = max(j - jj, i - ii);
            sr = max(1, i - ss + 1); sc = max(1, j - ss + 1); goto second_found;
        }

    ss = 1; sr = fr; sc = fc;

second_found:
    cout << sr << " " << sc << " " << ss;
}
