#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<char> ans(n);
    int idx = 0;

    for(int j = 0; j < n; j++) {
        bool blue = false, red = false, green = false;
        int i = idx;
        while((i < s.size()) && (!blue || !red || !green)) {
            if(s[i] == 'B') blue = true;
            if(s[i] == 'R') red = true;
            if(s[i] == 'G') green = true;
            i++;
        }
        ans[j] = s[i-1];  // Assign directly to the correct index
        idx = i;
    }

    for(auto c : ans) cout << c;  // Output the result
    cout << endl;
    
    return 0;
}