#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<vector<int>> grid(501, vector<int>(501, false));

        for(int i = 0; i < n; i++) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if(x1 > x2) {
                swap(x1,x2);
            }
            if(y1 > y2) {
                swap(y1,y2);
            }

            for(int i = x1; i < x2; i++) {
                for(int j = y1; j < y2; j++) {
                    grid[i][j] = true;
                }
            }
        }

        int total = 0;
        for(int i = 0; i < 500; i++) {
            for(int j = 0; j < 500; j++) {
                if(grid[i][j]) {
                    total++;
                }
            }
        }

        cout << total << "\n";
    }

}