#include <bits/stdc++.h>
using namespace std;

int main(){
    int config[] = {1,1,2,2,2,8};
    int tmp;
    for(int i = 0; i < 6; i++){
        cin >> tmp;
        cout << config[i] - tmp;
        if(i != 5)cout << " ";
    }
    return 0;
}