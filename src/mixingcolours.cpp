#include <bits/stdc++.h>
using namespace std;

const int MAX_RULES = 100;
const int MAX_COLORS = MAX_RULES*3;
map<string, int> color_to_code;
vector<string> colors(MAX_COLORS);
int ncolors = 0;

vector<vector<int> > combines(MAX_COLORS, vector<int>(MAX_COLORS, -1));
vector< map<int, double> > tokens;

int get_code(const string& color) {
    map<string, int>::iterator r = color_to_code.find(color);
    if (r != color_to_code.end())
        return r->second;
    int code = ncolors;
    ++ncolors;
    color_to_code[color] = code;
    colors[code] = color;
    return code;
}

string solve() {
    int T = tokens.size();
    vector< vector< map<int, double> > >dp(T, vector< map<int, double> >(T));

    for (int i = 0; i < T; ++i) {
        dp[i][i] = tokens[i];
        for (int j = i-1; j >= 0; --j) {
            for (int k = j; k < i; ++k) {
                for (map<int, double>::iterator up = dp[k][j].begin();
                     up != dp[k][j].end();
                     ++up)
                    for (map<int, double>::iterator right = dp[i][k+1].begin();
                         right != dp[i][k+1].end();
                         ++right) {
                        int gen = combines[right->first][up->first];
                        if (gen == -1)
                            continue;
                        double conf = right->second + up->second;
                        if (dp[i][j].find(gen) == dp[i][j].end())
                            dp[i][j][gen] = conf;
                        else
                            dp[i][j][gen] = max(conf, dp[i][j][gen]);
                    }
            }
        }
    }

    if (dp[T-1][0].empty())
        return "GAMEOVER";

    int result = 0;
    double conf = 0.0;
    conf = -1e99;
    for (map<int, double>::iterator it = dp[T-1][0].begin();
         it != dp[T-1][0].end(); ++it)
        if (it->second > conf) {
            result = it->first;
            conf = it->second;
        }

    return colors[result];
}

int main(int argc, char *argv[]) {
    int R;
    cin >> R;
    string a, b, c;
    for (int i = 0; i < R; ++i) {
        cin >> a >> b >> c;
        int ca = get_code(a);
        int cb = get_code(b);
        int cc = get_code(c);
        combines[ca][cb] = combines[cb][ca] = cc;
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int C;
        cin >> C;

        tokens = vector< map<int, double> > (C);
        for (int j = 0; j < C; ++j) {
            while (true) {
                string k;
                cin >> k;
                if (k == "END")
                    break;
                int ck = get_code(k);
                double conf;
                cin >> conf;
                tokens[j][ck] = log(conf);
            }
        }
        cout << solve() << endl;
    }
    return EXIT_SUCCESS;

}