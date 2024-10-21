#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int tmp;
    while(n--){
        cin >> tmp;
        string odd_even = (tmp % 2 == 0 ) ? "even" : "odd";
        cout << tmp << " is " << odd_even << "\n";
    }
    return 0;
}