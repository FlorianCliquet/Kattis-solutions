#include <bits/stdc++.h>

using namespace std;


#define nl "\n";
int N,M;


int main() {
    cin >> N;
    map<string, int> mp;
    
    while(N--) {
        string s, temp = "";
        cin >> s;
        for(auto x : s) {
            temp += x;
            mp[temp]++;
        }
    }
    
    cin >> M;
    
    while(M--) {
        string a;
        cin >> a;
        cout << mp[a] << nl;
    }
    return 0;
}