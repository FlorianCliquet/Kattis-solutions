#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x,y;
    while(n--){
        cin >> x >> y;
        cout << x << " " << (y * (y+3)) / 2 << "\n";
    }
    return 0;
}