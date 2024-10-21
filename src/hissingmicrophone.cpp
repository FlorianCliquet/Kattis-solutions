#include <bits/stdc++.h>
using namespace std;
int main(){
    string tmp;
    cin >> tmp;
    int a = tmp.find("ss");
    if(a == string::npos)cout << "no hiss";
    else cout << "hiss";
    return 0;
}