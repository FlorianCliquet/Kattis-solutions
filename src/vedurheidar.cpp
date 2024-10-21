#include <bits/stdc++.h>
using namespace std;
int main(){
    int v, n;
    cin >> v >> n;
    string tmp;
    int tmp_x;
    for(int i = 0; i < n; i++){
        cin >> tmp >> tmp_x;
        if(tmp_x < v)cout << tmp << " lokud" << "\n";
        else cout << tmp << " opin" << "\n";
    }
    return 0;
}