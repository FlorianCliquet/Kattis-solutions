#include <bits/stdc++.h>

using namespace std;

#define mod 2147483647
#define ll long long

ll dp[5020][2];
ll a[5020];
int n;
void add(ll &x, ll y){
    x += y;
    if(x >= mod)x-=mod;
}
int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i <= n; i++)scanf("%lld", &a[i]);
        dp[1][0] = 0, dp[1][1] = 1;
        for(int i = 2 ; i <= n; ++i){
            ll mx = a[i] , mi = a[i];
            dp[i][0] = 0, dp[i][1] = 0;
            for(int j = i -1; j >= 1; --j){
                if(a[j] > mx)add(dp[i][0], dp[j][1]);
                if(a[j] < mi)add(dp[i][1], dp[j][0]);
                mx = max(mx, a[j]);
                mi = min(mi, a[j]);
            }
            if(mi > a[0])add(dp[i][1], 1);
        }
        ll ans = 0;
        add(ans, dp[n][0]);
        add(ans, dp[n][1]);
        cout << ans << endl;
    }
    return 0;
}