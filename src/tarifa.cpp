#include <bits/stdc++.h>
using namespace std;
int main(){
    int X, N;
    cin >> X >> N;
    int total = 0;
    int tmp;
    while(N--){
        cin >> tmp;
        total += X - tmp;
    }
    cout << total + X;
    return 0;
}