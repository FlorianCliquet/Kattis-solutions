#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    string ans;
    int a_c = 0, b_c = 0;
    for(int i = 0; i < a; i++){
        cin >> ans;
        if(ans == "kjuklingur")a_c++;
        else b_c++;
    }
    if(a_c !=0 && b_c == 0)cout << "kjuklingur";
    else if(a_c == 0 && b_c != 0) cout << "nautakjot";
    else cout << "blandad best";
    return 0;
}