#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pb push_back
#define nl "\n"
#define IMPOSSIBLE cout << "IMPOSSIBLE\n"
typedef long long ll;


int main() {
    int t = 1;

    while(t--) {
        int n;
        cin >> n;

        vector<int> count(51, 0);
        for(int i = 0; i<10*n; i++) {
            for(int j = 0; j<5; j++) {
                int x;
                cin >> x;
                count[x]++;
            }
        }

        vector<int> res;
        int lim = 2*n;

        for(int i = 1; i<=50; i++) {
            if(count[i] > lim) {
                res.push_back(i);
            }
        }

        if(res.empty()) {
            cout << -1 << nl;
            return 0;
        }
        for(auto& i : res) cout << i << nl;
    }

    return 0;
}