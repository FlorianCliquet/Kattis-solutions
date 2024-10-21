#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<int>> Matrix;

Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
    Matrix result(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}

Matrix exponentiationDichotomique(const Matrix &A, long long int n) {
    if (n == 0) {
        return {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }
    if (n == 1) {
        return A;
    }

    if (n % 2 == 0) {
        Matrix halfPower = exponentiationDichotomique(A, n / 2);
        return multiplyMatrices(halfPower, halfPower);
    } else {
        return multiplyMatrices(A, exponentiationDichotomique(A, n - 1));
    }
}

long long int fibonacci(long long int n) {
    Matrix A = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 0, 1}
    };

    Matrix B = {
        {2}, // f(2)
        {1}, // f(1)
        {1}  // constant
    };

    if (n == 1) return B[1][0];  // f(1)
    if (n == 2) return B[0][0];  // f(2)
    
    Matrix An_minus_2 = exponentiationDichotomique(A, n - 2);

    Matrix X = multiplyMatrices(An_minus_2, B);

    return X[0][0] % MOD;  // Ensure the result is modded
}

int main() {
    long long int n;
    cin >> n;
    long long int result = fibonacci(n) % MOD; // This line is technically redundant as the return in `fibonacci` already mods
    cout << result << endl;

    return 0;
}
