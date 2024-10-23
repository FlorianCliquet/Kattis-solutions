#include <bits/stdc++.h>
using namespace std;

int main(){
    double r,c; cin >>r>>c;
    double result = (double)(r - c) * (r - c) / (r * r) * 100; 
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}