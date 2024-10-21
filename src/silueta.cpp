#include <bits/stdc++.h>
using namespace std;

int n, max_h = 0, max_r = 0, min_l = 1002;
vector<int> heights;
vector<vector<char>> image;
int main() {
    heights.assign(1002, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, l, h;
        cin >> l >> r >> h;
        max_h = max(max_h, h);
        max_r = max(max_r, r);
        min_l = min(min_l, l);
        for (int j = l; j < r; j++) {
            heights[j] = max(heights[j], h);
        }
    }

    int ans = 0;
    for (int i = min_l; i <= max_r; i++) {
        if (heights[i] != 0) {
            ans++;
        }
        ans += abs(heights[i] - heights[i - 1]);
    }
    image.assign(max_h + 1, vector<char>(1002, '.'));

    for (int i = min_l; i <= max_r; i++) {
        if (heights[i] >= heights[i - 1]) {
            for (int j = heights[i - 1]; j <= heights[i]; j++) {
                image[max_h - j][i] = '#';
            }
        } else {
            for (int j = heights[i - 1] - 1; j >= heights[i]; j--) {
                image[max_h - j][i - 1] = '#';
            }
            image[max_h - heights[i]][i] = '#';
        }
    }

    for (int i = 0; i < 1002; i++) {
        image[max_h][i] = '*';
    }

    cout << ans << endl;
    for (int h = 0; h <= max_h; h++) {
        for (int i = min_l; i < max_r; i++) {
            cout << image[h][i];
        }
        cout << endl;
    }

    return 0;
}