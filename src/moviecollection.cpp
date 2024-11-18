#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define nl "\n"

int N, M;
int arr[200100];
int pos[100100];

void update(int id, int val) {
    while (id <= N + M) {
        arr[id] += val;
        id += (id & -id);
    }
}

int sum(int id) {
    int res = 0;
    while (id) {
        res += arr[id];
        id -= (id & -id);
    }
    return res;
}

int main() {
    FAST_IO;
    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M;
        memset(arr, 0, sizeof(arr));

        // Initialize positions in Fenwick Tree
        for (int i = 1; i <= N; i++) {
            update(N - i + 1, 1); // Mark positions in Fenwick Tree
            pos[i] = N - i + 1;   // Corrected initialization of pos[i]
        }

        for (int i = 1; i <= M; i++) {
            int x;
            cin >> x;

            if (i > 1) cout << " ";
            // Count elements above x
            cout << N - sum(pos[x]);

            // Remove x from current position
            update(pos[x], -1);

            // Move x to the top of the stack
            pos[x] = N + i;
            update(pos[x], 1); // Mark new position
        }
        cout << "\n";
    }
    return 0;
}
