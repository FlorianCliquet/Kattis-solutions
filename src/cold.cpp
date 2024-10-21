#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        c += (tmp < 0);
    }
    cout << c;
    return 0;
}