#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    double alcoholContentShot1 = 0.0, alcoholContentShot2 = 0.0;

    for (int i = 0; i < n; ++i) {
        int volume, percent;
        cin >> volume >> percent;
        alcoholContentShot1 += volume * (percent / 100.0);
    }

    for (int i = 0; i < m; ++i) {
        int volume, percent;
        cin >> volume >> percent;
        alcoholContentShot2 += volume * (percent / 100.0);
    }

    if (abs(alcoholContentShot1 - alcoholContentShot2) < 1e-9) {
        cout << "same" << endl;
    } else {
        cout << "different" << endl;
    }

    return 0;
}
