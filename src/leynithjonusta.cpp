#include <iostream>
#include <vector>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

int main() {
    FAST_IO;
    string input;
    getline(cin, input);

    vector<char> ans;
    ans.reserve(input.size());

    for (char c : input) {
        if (c != ' ') {
            ans.push_back(c);
        }
    }

    cout.write(ans.data(), ans.size());
    return 0;
}
