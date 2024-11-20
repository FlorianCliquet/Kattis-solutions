#include <bits/stdc++.h>
using namespace std;

// **Pragmas** (comment out if not needed, i.e. for interactive problems)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// **Type Definitions**
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using si = set<int>;
using sc = set<char>;
using mii = map<int, int>;

// **Constants**
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

// **Utility Macros**
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)

// **Input/Output Macros**
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

// **Mathematical Utilities**
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) / gcd(a, b) * (b))

// **Debug Utilities** 
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl
    #define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#else
    #define debug(x)
    #define debug2(x, y)
#endif

// **Helper Functions**
template <typename T>
void print_v(const vector<T> &v) {
    for (const auto &x : v) cout << x << " ";
    cout << endl;
}

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

int get_mex(const vb& a){
    int m = 0;
    while(m < a.size() && a[m])m++;
    return m;
}

vi compute_grundy(int heap_max_size, vi& moves){
    vector<int> grundy(heap_max_size + 1, 0);
    rep(i,0,heap_max_size+1){
        vb reachables(moves.size() + 1, false);
        for(int move : moves)if(i - move >= 0)reachables[grundy[i - move]] = true;
        grundy[i] = get_mex(reachables);
    }
    return grundy;
}

string evaluate_pos(const vi& grundy, const vvi& positions){
    string result;
    for(const auto& pos : positions){
        int xor_sum = 0;
        for(int p : pos)xor_sum ^= grundy[p];
        result += xor_sum ? "W" : "L";
    }
    return result;
}

void solve() {
    int k; cin >> k;
    vi moves(k);
    rep(i,0,k)cin >> moves[i];
    int m,mx; cin >> m;
    vvi positions(m);
    rep(i,0,m){
        int x; cin >> x;
        positions[i].resize(x);
        rep(j,0,x){
            cin >> positions[i][j];
            mx = max(mx, positions[i][j]);
        }
    }
    vi grundy = compute_grundy(mx, moves);
    string res = evaluate_pos(grundy, positions);
    cout << res << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
