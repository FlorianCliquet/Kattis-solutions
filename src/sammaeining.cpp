#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
typedef long long ll;
const ll MOD = 1e9 + 7;

// Function to compute power with modulo: result = base^exp % mod
ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Main function to calculate the coefficient of x^7 modulo MOD
ll calculateCoefficient(ll n) {
    if (n < 10) {
        /**
         * Vector precoputed using the following formula:
         * Z_7[X] = (1+x)(1+x²)(1+x³)...(1+x^n)
         * Each value represents the coefficient of x^7 in the polynomial
         * P_0[X] = 0, P_1[X] = 0 ... P_9[X] = 51
         * Example for P_4[X]:
         * P_4[X] = (1+x)(1+x²)(1+x³)(1+x⁴) = 1 + 2x³ + 2x⁴ + x⁵ + 2x⁷ + x⁸ + x⁹
         * Soit le résultat est 2
         */
        return vector<ll>{0, 0, 0, 0, 2, 3, 6, 13, 25, 51}[n]; // Precomputed results
    }

    // k , r will be used to calculate the base answer
    ll k = n / 5;
    ll r = n % 5;

    // Calculate the base answer using the derived formula:
    // 32^k is used because the polynome grows exponentially for large n. The base 32 reflect the growth of the polynomial under modular arithmetic constraints.
    // 2^k represents a correction factor that accounts for symmetries in the polynomial that arise from the periodicity modulo 5.
    ll ans = (modPow(32, k, MOD) - modPow(2, k, MOD) + MOD) % MOD;
    ans = (ans * modPow(5, MOD - 2, MOD)) % MOD;

    // Adjust answer based on the remainder
    // we double the result because the first leftover term modifies the coefficient in a predictable way
    if (r >= 1)ans = (ans * 2) % MOD;
    // We double and add correction because it add further complexity to the polynomial
    if (r >= 2)ans = (ans * 2 + modPow(2, k, MOD)) % MOD;
    // We double and substract correction because the third element has the opposite effect compared to the second
    if (r >= 3)ans = (ans * 2 - modPow(2, k, MOD) + MOD) % MOD;
    // We double the result again and add correction because the fourth element behaves like the second one
    if (r >= 4)ans = (ans * 2 + modPow(2, k, MOD)) % MOD;
    // normalized back to the correct scale by multiplying by the modular inverse of 2
    ans = (ans * modPow(2, MOD - 2, MOD)) % MOD;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << calculateCoefficient(n) << endl;
    return 0;
}
