#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
int main() {
    int n;
    cin >> n;

    while(n--) {
        double big, small, space;
        cin >> big >> small >> space;

        double l = (big - small) / 2;

        double angle1 = acos((-pow(small+space, 2) + (2*pow(l, 2))) / (2*pow(l, 2))) * 180/M_PI;

        cout << fixed;
        cout.precision(0);
        cout << floor(360 / angle1) << endl;
    }
}