#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c = 0, tmp; cin >> n;
    while(n--){
        cin >> tmp;
        if (tmp % 2 != 00)c++;
    }
    cout << c;
    return 0;
}