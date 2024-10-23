#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<long long int>> Matrix;

Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
    Matrix result(2, vector<long long int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}

Matrix exponentiationDichotomique(const Matrix &A, long long int n) {
    if (n == 0) {
        return {{1, 1},{1, 2}};
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

Matrix fibs_or_dibs(long long int n, long long int a, long long int b) {
    Matrix A = {
        {1, 1},
        {1, 2}
    };

    Matrix B = {
        {a},
        {b},
    };
    
    Matrix An_minus_2 = exponentiationDichotomique(A, n);

    Matrix X = multiplyMatrices(An_minus_2, B);

    return X;
}

int main() {
    long long int a, b;
    cin >> a >> b;
    long long int n;
    cin >> n;
    if(n == 0)cout << a << " " << b << endl;
    else{
      Matrix result = fibs_or_dibs(n,a,b);
      cout << result[0][0] << " " << result[1][0] << endl;
    }
    return 0;
}
