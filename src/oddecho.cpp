#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(){
    FAST_IO;
    int N;
    cin >> N;
    vector<string> ans;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(i % 2 == 0){
            ans.push_back(input);
        }
    }
    for(const auto& c : ans)
        cout << c << "\n";
    return 0;
}
