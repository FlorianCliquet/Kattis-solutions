#include <bits/stdc++.h>
using namespace std;

int main(){
    string c;
    cin >> c;
    int a = c.find("a");
    a = (a == -1) ? 0 :a;
    cout << c.substr(a);
    return 0;
}