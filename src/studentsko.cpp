#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int n, k;
int main() {
    FAST_IO
    unordered_map<int, int> m;
    cin >> n >> k;
    vector<int> arr, v;
    arr.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v[i] = arr[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        m[v[i]] = i / k;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = m[arr[i]];
    }
    vector<int> L(n, 0);  
    int k = 0;            
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(L.begin(), L.begin() + k, arr[i]) - L.begin();
        L[pos] = arr[i];
        if (pos == k) {
            k++;
        }
    }
    cout << n - k << endl;

    return 0;
}