#include <bits/stdc++.h>
using namespace std;

int pow(int x, int y){
    int result = 1;
    while(y--){
        result*=x;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    int ans = 0;
    int tmp;
    while(n--){
        cin >> tmp;
        ans += pow(tmp/10,tmp%10);
    }
    cout << ans;
    return 0;
}