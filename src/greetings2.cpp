#include <bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin >> input;
    int e_c = count(input.begin(),input.end(), 'e');
    string ans = "h";
    ans += string(e_c * 2, 'e');
    ans += "y";
    cout << ans;
    return 0;
}