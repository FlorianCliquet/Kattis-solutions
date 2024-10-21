#include <bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin >> input;
    int b_count = count(input.begin(),input.end(), 'b');
    int k_count = count(input.begin(),input.end(), 'k');
    if(k_count > b_count)cout << "kiki";
    else if(k_count == b_count && k_count != 0)cout <<"boki";
    else if(b_count > k_count)cout << "boba";
    else if(b_count == 0 && k_count == 0)cout << "none";
    return 0;
}