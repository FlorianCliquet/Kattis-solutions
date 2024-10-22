#include <bits/stdc++.h>
using namespace	std;
#define FAST_IO                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

/**
 * This problem is a simple implementation of Faulhaber's formula
 * for the sum of the first n powers of the first n integers.
 * Wikipedia: https://en.wikipedia.org/wiki/Faulhaber%27s_formula
 * sum(n^k) = 1/(k+1) * sum_{i=0}^{k} C(k+1, i) * B_i * n^{k+1-i}
 */

typedef long long ll;
const ll mod  = 1e9 + 7;

ll power(ll x, ll y, ll p){
    ll res = 1;
    /**
     * modular exponentiation algorithm
     * if y is odd, multiply x with result and divide y by 2
     * then multiply x by itself and divide y by 2
     */
    x =x% p;
    while(y > 0){
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int	main(){
	FAST_IO;
    ll n,k; cin >> n >> k;

    // Precompute factorials array , used to calculate binomial coefficients
    vector<ll> fact(k+2, 1);
    for(ll i = 1; i <= k+1; i++)fact[i] = (fact[i-1] * i) % mod;

    // Precompute Bernoulli numbers
    vector<ll> b(k + 1, 1);  // Create a vector to store Bernoulli numbers, initialized with 1s (B_0 = 1)

    // Loop to compute the Bernoulli numbers from B_1 to B_k
    for (ll i = 1; i <= k; ++i) {
        ll sm = 0;  // 'sm' will store the accumulated sum for the Bernoulli number B_i

        // We need to compute B_i using the following formula:
        // B_i = -(1 / (i + 1)) * sum_{j=0}^{i-1} C(i+1, j) * B_j
        // This loop iterates over all previous Bernoulli numbers B_0, B_1, ..., B_(i-1)

        for (ll j = 0; j < i; ++j) {
            // We are calculating: C(i+1, j) * B_j
            // C(i+1, j) is the binomial coefficient, given by:
            // C(i+1, j) = (i+1)! / (j! * (i+1-j)!)
            
            // Breaking down the term:
            // fact[i+1] gives (i+1)!
            // power(fact[j], mod - 2, mod) gives the modular inverse of j! (modular division by j!)
            // power(fact[i+1-j], mod - 2, mod) gives the modular inverse of (i+1-j)! (modular division by (i+1-j)!)
            // b[j] is the previously computed Bernoulli number B_j

            // Summing up the current term:
            sm += fact[i + 1] * power(fact[j], mod - 2, mod) % mod * power(fact[i + 1 - j], mod - 2, mod) % mod * b[j] % mod;
            sm %= mod;  // Apply mod to keep the sum within bounds
        }

        // Now we need to compute the final Bernoulli number B_i:
        // B_i = -(1 / (i + 1)) * sm
        // Since we are working with modular arithmetic, division is replaced by multiplying with the modular inverse.
        sm *= power(mod - i - 1, mod - 2, mod);  // Multiply by the modular inverse of (i+1) to divide by (i+1)
        sm %= mod;  // Apply mod again to keep the result in range

        b[i] = sm % mod;  // Store the final value of B_i in the Bernoulli number vector
    }


    ll sm = 0;
    // We now compute the sum for Faulhaber's formula, which sums up the powers of integers
    // using precomputed Bernoulli numbers and binomial coefficients.
    for (ll i = 0; i <= k; i++) {
        // Compute the term for each i in the summation:
        // The general term involves binomial coefficients, Bernoulli numbers, and powers of (n + 1)

        // First, calculate the binomial coefficient C(k+1, i)
        // C(k+1, i) = (k+1)! / (i! * (k+1-i)!)
        // In modular arithmetic, division is performed using the modular inverse
        ll trm = fact[k + 1] * power(fact[i], mod - 2, mod) % mod * power(fact[k + 1 - i], mod - 2, mod) % mod;

        // Next, multiply the binomial coefficient by the Bernoulli number B_i
        trm = trm * b[i] % mod;
        // Finally, multiply the entire term by (n + 1)^(k + 1 - i)
        trm = trm * power(n + 1, k + 1 - i, mod) % mod;
        trm %= mod;
        sm += trm;
        sm %= mod;
    }

    // Finally, after the loop, we need to multiply the entire sum by the modular inverse of (k + 1)
    sm = sm * power(k + 1, mod - 2, mod) % mod;

    cout << sm << endl;
	return 0;
}