#define FASTIO  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

int main() {
    FASTIO;
    string s, toRemove;
    cin >> s >> toRemove;

    // Length of the substring to remove
    size_t toRemoveLength = toRemove.length();

    // Resulting string, initially empty
    string result;

    // Iterate through each character in the original string
    for (char c : s) {
        result.push_back(c); // Add the current character to the result

        // Check if the end of the result matches the substring to remove
        if (result.size() >= toRemoveLength && 
            equal(result.end() - toRemoveLength, result.end(), toRemove.begin())) {
            // If it matches, remove the substring from the result
            result.resize(result.size() - toRemoveLength);
        }
    }

    // If the resulting string is empty, print "FRULA"
    if (result.empty()) {
        cout << "FRULA" << endl;
    } else {
        cout << result << endl; // Output the modified string
    }

    return 0;
}