#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("fast-math")
// Function to solve the problem
double solve(const vector<double>& a, int K) {
    int N = a.size();  // Size of the input array
    double result = 0;  // Final result
    double pfail[N + 1];  // Probability of failure prefix array

    pfail[0] = 1;
    for (int i = 1; i < K; ++i) {
        pfail[i] = 1 - a[i - 1];  // Initialize the pfail array
    }

    int zero_count = 0;  // Count of zeros in the current window
    double prod = 1;     // Product of probabilities in the current window

    // Initialize the first window of size K
    for (int i = 0; i < K; ++i) {
        zero_count += (a[i] == 0);
        prod *= (a[i] != 0)*a[i] + (a[i] == 0);
    }

    // Iterate over the array, starting from index K-1
    for (int i = K - 1; i < N; ++i) {
        double p = a[i];
        pfail[i + 1] = (1 - result) * (1 - p);

        // Update result if there are no zeros in the window
        result += (zero_count == 0) * prod * pfail[i - K + 1];

        // Prepare for the next iteration, adjust window
        zero_count += (i != N - 1)*((a[i + 1] == 0) - (a[i - K + 1] == 0));
        prod *= (i != N - 1)*((a[i + 1] == 0 ? 1 : a[i + 1]) / (a[i - K + 1] == 0 ? 1 : a[i - K + 1]));
    }

    return result;
}

int main() {
    FAST_IO;
    cin.exceptions(cin.failbit);

    // Input handling
    int N, K;
    cin >> N >> K;
    assert(1 <= K && K <= N);

    vector<double> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Output the result
    cout << setprecision(10) << fixed << solve(a, K) << endl;
}
