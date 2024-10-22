#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;

int A[MAX];
int B[MAX];
int n;

void add(int x, long long value) {
    int i = x;
    do {
        A[i] += value;
        i = (i + 3) % n;
    } while (i != x);
}

int init(int x) {
    int i = x;
    long long value = 0;
    long long min_value = 0;

    do {
        A[i] = value; // Set the current position to value
        min_value = min(min_value, value); // Track the minimum value
        i = (i + 1) % n;

        value -= B[i]; // Update value by subtracting B[i]
        i = (i + 1) % n;

        value += B[i]; // Update value by adding B[i]
        i = (i + 1) % n;
    } while (i != x);

    return min_value; // Return the minimum value encountered
}

int main() {
    cin >> n; // Read the number of elements
    for (int i = 0; i < n; ++i) {
        cin >> B[i]; // Read the transformed ring B
    }

    if (n % 3 != 0) {
        init(0); // Initialize the first chain
        add(0, (B[1] - A[0] - A[1] - A[2]) / 3); // Adjust values
    } else {
        add(0, 1 - init(0)); // Adjust first chain
        add(1, 1 - init(1)); // Adjust second chain
        init(2); // Initialize the third chain
        add(2, B[1] - A[0] - A[1]); // Adjust third chain
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i] << endl; // Output the original ring A
    }

    return 0;
}
