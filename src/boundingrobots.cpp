#include <bits/stdc++.h>
using namespace std;
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

void solve(int width, int length) {
    int n;
    cin >> n; // Number of commands
    int actual_x = 0, actual_y = 0; // Robot starts at (0, 0)
    int thinks_x = 0, thinks_y = 0;

    while (n--) {
        char c;
        int d;
        cin >> c >> d; // Read command (direction and distance)
        
        // Update where the robot thinks it is
        switch (c) {
            case 'u': thinks_y += d; break;
            case 'd': thinks_y -= d; break;
            case 'r': thinks_x += d; break;
            case 'l': thinks_x -= d; break;
        }

        // Calculate the actual position considering the room boundaries
        switch (c) {
            case 'u':
                actual_y = min(length - 1, actual_y + d);
                break;
            case 'd':
                actual_y = max(0, actual_y - d);
                break;
            case 'r':
                actual_x = min(width - 1, actual_x + d);
                break;
            case 'l':
                actual_x = max(0, actual_x - d);
                break;
        }
    }

    // Output the result for this simulation
    cout << "Robot thinks " << thinks_x << " " << thinks_y << endl;
    cout << "Actually at " << actual_x << " " << actual_y << endl;
}

int main(){
    int x = fast_input(), y = fast_input();
    while(x != 0 && y != 0){
        solve(x, y);
        x = fast_input();
        y = fast_input();
    }
  return 0;
}
