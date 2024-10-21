#include <bits/stdc++.h>
using namespace std;
int l_f_d(int x){
    int fact = 1;
    while(x)
        fact *= x--;
    return fact % 10;
}

int main(){
    int n;
    cin >> n;
    int tmp;
    while(n--){
        cin >> tmp;
        cout << l_f_d(tmp) << "\n";
    }
    return 0;
}