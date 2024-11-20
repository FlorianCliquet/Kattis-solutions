#include <cstdio>

#define ull unsigned long long // Use a specific alias for unsigned long long
using namespace std;

// Global variables
ull P[(int)4e6 + 10], H, a[2005][2005]; // Powers of base, hash grid
char s[2005];                           // Input line buffer

int main() { // Keep the return type as int for main
    P[0] = 1;
    // Precompute powers of base 43
    for (ull i = 1; i < 4e6 + 10; ++i) 
        P[i] = P[i - 1] * 43;
    
    // Input dimensions and initialize variables
    ull n, m, x, y;
    scanf("%llu%llu%llu%llu", &n, &m, &x, &y);
    
    // Compute hashes for the canvas grid
    for (ull i = 0; i < n; ++i) {
        scanf("%s", s);
        for (ull j = 0; j < m; ++j) {
            // Update hash using a rolling hash method
            H = H * 43 + (s[j] == 'x'); 
        }
    }

    // Compute hashes for the pattern grid
    for (ull i = 1; i <= x; ++i) {
        scanf("%s", s + 1);
        for (ull j = 1; j <= y; ++j) {
            // Pattern hash uses same rolling hash technique
            a[i][j] = a[i][j - 1] * 43 + (s[j] == 'x');
        }
    }

    // Start pattern matching
    ull ans = 0; // Counter for matches
    for (ull j = 1; j + m < y + 2; ++j) { 
        ull t = 0;
        for (ull i = 1; i <= n; ++i) {
            t = t * P[m] + (a[i][j + m - 1] - a[i][j - 1] * P[m]);
        }
        if (t == H) ++ans;
        for (ull i = 2; i + n < x + 2; i++) {
            t -= (a[i - 1][j + m - 1] - a[i - 1][j - 1] * P[m]) * P[n * m - m];
            t = t * P[m] + (a[i + n - 1][j + m - 1] - a[i + n - 1][j - 1] * P[m]);
            if (t == H) ++ans;
        }
    }

    printf("%llu\n", ans); // Output the number of matches
    return 0; // Return 0 explicitly
}