#include <bits/stdc++.h>
using namespace std;
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct coord {
    double x;
    double y;
};

double area(deque<coord>& v) {
    int n = v.size();
    double total = 0;
    for(int i=0, j=1; i < n; i++, j=(i+1)%n)total += (v[i].x * v[j].y) - (v[i].y * v[j].x);
    return abs(total) / 2;
}

coord scalepoint(coord lo, coord hi, double level) {
    double scalefactor = (level - lo.y) / (hi.y - lo.y);
    return {scalefactor * (hi.x - lo.x) + lo.x, level};
}

bool calc(deque<coord> v, double level, double target) {
    deque<coord> before;
    deque<coord> above;
    deque<coord> after;

    bool mid = false;
    for(auto i : v) {
        if(i.y > level) {
            mid = true;
            above.push_back(i);
        }
        else {
            if(!mid) before.push_back(i);
            else after.push_back(i);
        }
    }

    if(before.size() == 0 || after.size() == 0)return false;

    coord left, right;
    left = scalepoint(after.front(), above.back(), level);
    right = scalepoint(before.back(), above.front(), level);

    deque<coord> out;
    for(int i = 0; i < before.size(); i++)out.push_back(before[i]);
    out.push_back(right);
    out.push_back(left);
    for(int i = 0; i < after.size(); i++)out.push_back(after[i]);
    return area(out) >= target;
}

int main() {
    int n;
    cin >> n;

    double d, l;
    cin >> d >> l;

    double hi = -2005;
    double lo = 2005;
    deque<coord> v(n);
    for(auto& i : v) {
        cin >> i.x >> i.y;
        hi = max(hi, i.y);
        lo = min(lo, i.y);

    }

    // Make sure rotated correctly
    while(v.front().y != 0 || v.back().y != 0) {
        v.push_back(v.front());
        v.pop_front();
    }

    // Binary search on answer
    double target = (l*1000) / d;
    while(abs(hi - lo) > .00001) {
        double mid = (hi-lo)/2 + lo;
        if(calc(v, mid, target))hi = mid;
        else lo = mid;
    }

    cout << fixed;
    cout.precision(2);
    cout << lo << endl;
}