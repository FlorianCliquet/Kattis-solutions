#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar()
inline int fast_input() {
    int x = 0;
    char c;
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));
    if (c == EOF) return -1;
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');
    return x;
}

// Custom hash function for std::tuple<int, int, int, int>
struct tuple_hash {
    template <class T>
    size_t operator()(const tuple<T, T, T, T>& t) const {
        return hash<T>{}(get<0>(t)) ^ hash<T>{}(get<1>(t)) ^ hash<T>{}(get<2>(t)) ^ hash<T>{}(get<3>(t));
    }
};

// Memoization map
unordered_map<tuple<int, int, int, int>, int, tuple_hash> mem;

int f(int a, int b, int c, int r, int s) {
    if (a == 0 && b == 0 && c == 0) return (r > 0) ? 1 : 0;

    auto tup = make_tuple(a, b, c, r);
    if (mem.find(tup) != mem.end()) return mem[tup];

    int ans = INT_MAX;

    // Optimize the recursive calls by checking conditions first
    if (a > 0) {
        ans = min(ans, (r <= s - 1 ? f(a - 1, b, c, r + 1, s) : 1 + f(a - 1, b, c, 1, s)));
    }
    if (b > 0) {
        ans = min(ans, (r <= s - 2 ? f(a, b - 1, c, r + 2, s) : 1 + f(a, b - 1, c, 2, s)));
    }
    if (c > 0) {
        ans = min(ans, (r <= s - 3 ? f(a, b, c - 1, r + 3, s) : 1 + f(a, b, c - 1, 3, s)));
    }

    mem[tup] = ans;
    return ans;
}

int main() {
    FAST_IO // Enable fast I/O

    // Read inputs using fast_input()
    int a = fast_input(), b = fast_input(), c = fast_input(), s = fast_input();
    
    // Call the function and output the result
    cout << f(a, b, c, 0, s) << endl;
    return 0;
}
