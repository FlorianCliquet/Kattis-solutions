#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,tmp;
    cin >> n;
    string ans = "",input;
    int max_c = -1;
    for(int i =0; i < n;i++){
        cin >> input >> tmp;
        if(tmp > max_c){
            max_c = tmp;
            ans = input;
        }
    }
    cout << ans;
    return 0;
}