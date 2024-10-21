#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double solve(double* a, int N, int K) {
    double result = 0;  // Final result
    double* pfail = (double*)malloc((N + 1) * sizeof(double));  // Probability of failure prefix array

    pfail[0] = 1.0;
    for (int i = 1; i < K; ++i) {
        pfail[i] = 1.0 - a[i - 1];  // Initialize the pfail array
    }

    int zero_count = 0;  // Count of zeros in the current window
    double prod = 1.0;   // Product of probabilities in the current window

    // Initialize the first window of size K
    for (int i = 0; i < K; ++i) {
        zero_count += (a[i] == 0);
        prod *= (a[i] != 0) ? a[i] : 1; // Handle zero cases
    }

    // Iterate over the array, starting from index K-1
    for (int i = K - 1; i < N; ++i) {
        double p = a[i];
        pfail[i + 1] = (1.0 - result) * (1.0 - p);

        // Update result if there are no zeros in the window
        if (zero_count == 0) {
            result += prod * pfail[i - K + 1];
        }

        // Prepare for the next iteration, adjust window
        zero_count += (i != N - 1) * ((a[i + 1] == 0) - (a[i - K + 1] == 0));
        prod *= (i != N - 1) * ((a[i + 1] == 0 ? 1 : a[i + 1]) / (a[i - K + 1] == 0 ? 1 : a[i - K + 1]));
    }

    free(pfail);  // Free the allocated memory
    return result;
}

int main() {
    // Input handling
    int N, K;
    scanf("%d %d", &N, &K);
    assert(1 <= K && K <= N);

    double* a = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &a[i]);
    }

    // Output the result
    printf("%.10lf\n", solve(a, N, K));

    free(a);  // Free the allocated memory
    return 0;
}
