#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,r,e,c;
    cin >> n;
    while(n--){
        cin >> r >> e >> c;
        if(r > e - c)cout << "do not advertise" << "\n";
        else if(r == e - c)cout << "does not matter" << "\n";
        else cout << "advertise" << "\n";
    }
    return 0;
}