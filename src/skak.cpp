#include <bits/stdc++.h>
using namespace std;
int main(){
    int x_r,y_r,x_p,y_p;
    cin >> x_r >> y_r >> x_p >> y_p;
    if(x_r != x_p && y_r != y_p)cout << "2";
    else if(x_r == x_p || y_r == y_p) cout << "1";
    return 0;
}