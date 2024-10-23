#include <stdio.h>
#include <stdlib.h>

#define MAX_M 18
#define INF (1 << 30)

// Function to find the next greater element for each element in the array
void nextGreaterElement(int* a, int* b, int n) {
    int s[n]; // Stack to hold indices
    int c = 0; // Counter for stack size

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the current element is greater than the stack's top element
        while (c > 0 && a[s[c - 1]] <= a[i]) {
            b[s[--c]] = i; // Update next greater element
        }
        s[c++] = i; // Push current index onto the stack
    }
    // Assign -1 to elements that do not have a next greater element
    while (c > 0) {
        b[s[--c]] = -1;
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q); // Read number of elements and number of queries

    int a[n]; // Input array
    int b[MAX_M][n]; // 2D array for storing next greater elements at each level

    // Read input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Compute next greater elements for the first level
    nextGreaterElement(a, b[0], n);

    // Precompute next greater elements for higher levels
    for (int i = 1; i < MAX_M; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i - 1][j] != -1) {
                b[i][j] = b[i - 1][b[i - 1][j]];
            } else {
                b[i][j] = -1; // Maintain -1 for unmatched elements
            }
        }
    }

    // Process each query
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y); // Read query parameters
        x--; // Convert to 0-based index

        // Find the result using binary lifting technique
        for (int i = MAX_M - 1; i >= 0; i--) {
            if (y >= (1 << i)) {
                y -= (1 << i);
                x = (x == -1 ? -1 : b[i][x]);
            }
        }

        // Output the result
        if (x != -1) {
            printf("%d\n", x + 1); // Convert back to 1-based index for output
        } else {
            printf("leik lokid\n"); // No greater element found
        }
    }

    return 0;
}
