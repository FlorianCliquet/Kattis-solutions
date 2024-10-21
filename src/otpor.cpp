#include <bits/stdc++.h>

using namespace std;

struct Expr {
    bool series = true;
    vector<long double> R;

    long double eval() {
        long double result = 0.0;
        if (series) {
            for (long double r : R) result += r;
        } else {
            for (long double r : R) result += 1.0 / r;
            result = 1.0 / result;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long double> R(N);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    string expression;
    cin >> expression;

    stack<Expr> exprStack;
    long double result = 0.0;

    for (char ch : expression) {
        if (ch == '(') {
            exprStack.push(Expr());
        } else if (ch >= '1' && ch <= '9') {
            int index = ch - '1';
            exprStack.top().R.push_back(R[index]);
        } else if (ch == '-') {
            exprStack.top().series = true;
        } else if (ch == '|') {
            exprStack.top().series = false;
        } else if (ch == ')') {
            long double evaluated = exprStack.top().eval();
            exprStack.pop();
            if (exprStack.empty()) {
                result = evaluated;
            } else {
                exprStack.top().R.push_back(evaluated);
            }
        }
    }

    // Output result with 6 decimal precision
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
