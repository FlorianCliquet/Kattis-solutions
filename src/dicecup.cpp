#include <bits/stdc++.h>

using namespace std;


int main(){
    double N,M;
    cin >> N >> M;
    double diff = abs(N-M);
    if(diff == 0)
        cout << (N+1)/2 + (M+1)/2 << endl;
    else{
        double mid = (N+1)/2 + (M+1)/2 - diff/2;
        for(int i = 0; i <= diff; i++){
            cout << mid << "\n";
            mid++;
        }
    }
}