#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n>>x;
    int sum =0;
    int tmp;
    for(int i = 0; i < n ; i++){
        cin >> tmp;
        sum += tmp;
    }
    if(sum <= x)cout << "Jebb";
    else cout <<"Neibb";
    return 0;
}