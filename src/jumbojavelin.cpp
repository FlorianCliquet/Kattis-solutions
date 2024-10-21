#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int res = -n + 1;
    int tmp;
    while(n--){
        cin >> tmp;
        res += tmp;
    }
    cout << res;
    return 0;
}