#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin >> m>>n;
    double point = 0;
    double hashtague = 0;
    string input;
    for(int i = 0; i < n;i++){
        cin >> input;
        for(const char& c : input){
            if (c == '#')hashtague++;
            else point++;
        }
    }
    if(hashtague == 0)cout << "1";
    else
        cout << point / (hashtague + point) << endl;
    return 0;
}