#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x,y;
    double result = 0;
    while(n--){
        cin >> x >> y;
        result += x*y;
    }
    cout << result;
    return 0;
}