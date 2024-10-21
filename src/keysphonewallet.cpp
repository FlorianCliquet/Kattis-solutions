#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int keys = 0, phone = 0, wallet = 0;
    string input;
    
    while(n--){
        cin >> input;
        if(input == "keys") keys++;
        else if(input == "phone") phone++;
        else if(input == "wallet") wallet++;
    }
    
    if(keys == 0) cout << "keys" << "\n";
    if(phone == 0) cout << "phone" << "\n";
    if(wallet == 0) cout << "wallet" << "\n";
    
    if(keys > 0 && phone > 0 && wallet > 0) 
        cout << "ready";
    
    return 0;
}
