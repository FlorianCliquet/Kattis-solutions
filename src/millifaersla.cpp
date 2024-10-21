#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >>a >> b>>c;
    int min_x = min({a,b,c});
    if(min_x == a)
        cout << "Monnei";
    else if(min_x == b)
        cout <<"Fjee";
    else
        cout <<"Dolladollabilljoll";
    return 0;
}