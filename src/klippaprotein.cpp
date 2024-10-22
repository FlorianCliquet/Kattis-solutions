#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define inf int(1e18)

#define fast() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int32_t main()
{
    fast();
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    int ans = n;


    set<char> st(s.begin(), s.end()); // Avoid duplicates
    for (const char &c : st)
    {
        int temp = 0;
        int prev_skip = -inf;
        for (int i = 0; i < n; i++)
        {
            /**
             * i - prev_skip + 1 <= k
             * This condition is to check if we can skip the current character based on the value of k
             * On the first occurence of a character, we don't skip it because i - prev_skip + 1 <=> i - (-inf) + 1 = i + inf + 1 > k
             * On other occurences, we skip the character if i - prev_skip + 1 <= k
             */
            if (i - prev_skip + 1 <= k) continue; 
            if (s[i] != c)
            {
                temp++; // Increment the answer
                prev_skip = i; // Update the last occurence of the character
            }
        }
        ans = min(ans, temp);
    }

    cout << ans;
    return 0;
}
