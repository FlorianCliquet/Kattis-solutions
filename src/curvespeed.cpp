#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
    double X,Y;
    while(cin >> X){
        cin >> Y;
        double A = sqrtl((X*(Y + 0.16)) / 0.067);
        cout << round(A) << "\n"; 
    }
    return 0;
}