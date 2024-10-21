#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(){
    FAST_IO;
    int n ,k;
    cin >> n>>k;
    int bag_idx = -1;
    int tmp;
    for(int i = 0; i < n && bag_idx == -1; i++){
        cin >> tmp;
        if(tmp == k)bag_idx = i;
    }
    if(bag_idx == 0)cout << "fyrst";
    else if(bag_idx == 1) cout << "naestfyrst";
    else cout << bag_idx + 1 << " fyrst";
    return 0;
}