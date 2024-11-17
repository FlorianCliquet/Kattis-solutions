#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int sum(int id) {
    int res = 0;
    while(id > 0) {
        res += arr[id-1];
        id &= (id - 1);
    }
    return res;
}

int get(int id) {
    return sum(id + 1) - sum(id);
}

void update(int id, int val) {
    while(id < arr.size()) {
        arr[id] += val;
        id |= (id+1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        int N, Q;
        cin >> N >> Q;
        
        arr = vector<int>(N+1, 0);
        for(int i = 0; i<Q; i++) {
            char type;
            cin >> type;
            
            if(type == 'F') {
                int pos;
                cin >> pos;
                
                int val = get(pos);
                val = (val == 0) ? 1 : -1;
                update(pos, val);
            } else if(type == 'C') {
                int l,r;
                cin >> l >> r;
                int count = sum(r+1) - sum(l);
                cout << count << "\n";
            }
        }
    }
    
    return 0;
}
