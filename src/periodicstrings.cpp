#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

bool is_k_periodic(const string& s, int k) {
    int n = s.size();
    if (n % k != 0) return false; // Length must be a multiple of k

    // Check each k-length segment
    for (int i = 1; i < n / k; ++i) {
        string previous = s.substr((i - 1) * k, k);
        string current = s.substr(i * k, k);
        
        // Right-rotate the previous substring by one
        char last_char = previous.back();
        previous.pop_back();
        previous.insert(previous.begin(), last_char);
        
        if (current != previous) return false; // The rotation rule fails
    }
    return true;
}

int find_min_k_periodic(const std::string& s) {
    int n = s.size();
    
    for (int k = 1; k <= n; ++k)if (is_k_periodic(s, k)) return k;
    return n; // If no k found, k = n (entire string itself)
}

int main() {
    FAST_IO;
    string s;cin >> s;
    cout << find_min_k_periodic(s) << endl;
    return 0;
}
