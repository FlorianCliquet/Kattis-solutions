#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,tmp,sum = 0; cin >> n;
    for(int i= 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
    }
    cout << sum / n;
    return 0;
}