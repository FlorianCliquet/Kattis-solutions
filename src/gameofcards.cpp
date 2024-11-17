#include <bits/stdc++.h>

#define len(a) (int)(a.size())
#define pb push_back

using namespace std;

int get_mex(vector<int>& a) {
    int am = len(a) + 3;
    vector<int> have(am);
    for(auto& x : a) if(x < am) have[x] = 1;
    int mex = 0;
    while(have[mex]) mex++;
    return mex;
}

void solve() {
    int p, k;
    cin >> p >> k;
    int ans = 0;
    for(int i = 0; i < p; i++) {
        int n; cin >> n;
        vector<int> c(n + 1);
        for(int j = 1; j <= n; j++) cin >> c[j];
        vector<int> state(n + 1);
        for(int j = 1; j <= n; j++) {
            vector<int> transitions;
            for(int take_top = 0; take_top <= k && take_top < j; take_top++) {
                int card = c[j - take_top];
                if(j - take_top - card >= 0) transitions.pb(state[j - take_top - card]);
            }
            state[j] = get_mex(transitions);
        }
        ans ^= state[n];
    }
    if(!ans) cout << "Bob will win.";
    else cout << "Alice can win.";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}