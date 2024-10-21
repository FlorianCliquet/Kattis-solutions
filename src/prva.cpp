#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar()
inline int fast_input() {
    int x = 0;
    char c;

    // Skip non-numeric characters, check for EOF
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

int main() {
    FAST_IO;
    int R = fast_input(), C = fast_input();
    vector<vector<char>> grid(R, vector<char>(C));
    
    // Reading the grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            grid[i][j] = getchar();
        }
        getchar(); // Consume the newline character after each row
    }
    
    string ans = "";

    // Function to update the answer with lexicographical comparison
    auto update_answer = [&](string &current_string) {
        if (current_string.size() > 1) {
            if (ans.empty() || strcmp(current_string.c_str(), ans.c_str()) < 0) {
                ans = current_string;
            }
        }
    };

    // Horizontal and vertical scans
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // Horizontal scan - left to right
            if (grid[i][j] != '#') {
                string tmp = "";
                int h_j = j;
                
                // Scan left from current position
                while (h_j >= 0 && grid[i][h_j] != '#') {
                    tmp += grid[i][h_j];
                    h_j--;
                }
                reverse(tmp.begin(), tmp.end());
                h_j = j + 1;
                // Scan right from current position
                while (h_j < C && grid[i][h_j] != '#') {
                    tmp += grid[i][h_j];
                    h_j++;
                }
                // Update answer after horizontal scan
                update_answer(tmp);
            }

            bool good = true;
            for(int k = 0; k < i; k++){
                if(grid[k][j] != '#') good = false;
            }
            // Vertical scan - top to bottom
            if (good && grid[i][j] != '#') {
                string tmp = "";
                int i_dx = i;
                
                // Scan downwards from current position
                while (i_dx < R && grid[i_dx][j] != '#') {
                    tmp += grid[i_dx][j];
                    i_dx++;
                }
                // Update answer after vertical scan
                update_answer(tmp);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
