#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double dist_squared(const Point& other) const {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
};

class LineSegment {
public:
    static const int COLINEAR = 0;
    static const int CLOCKWISE = 1;
    static const int COUNTER_CLOCKWISE = 2;

    Point a, b;

    LineSegment(double x1, double y1, double x2, double y2) 
        : a(x1, y1), b(x2, y2) {}

    double length_squared() const {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    bool contains(const Point& point) const {
        return min(a.x, b.x) <= point.x && point.x <= max(a.x, b.x) &&
               min(a.y, b.y) <= point.y && point.y <= max(a.y, b.y);
    }

    int orientation(const Point& point) const {
        double val = (a.y - b.y) * (point.x - a.x) - (a.x - b.x) * (point.y - a.y);
        if (val > 0) return CLOCKWISE;
        if (val < 0) return COUNTER_CLOCKWISE;
        return COLINEAR;
    }

    bool intersects(const LineSegment& other) const {
        int o1 = orientation(other.a);
        int o2 = orientation(other.b);
        int o3 = other.orientation(a);
        int o4 = other.orientation(b);

        // General case
        if (o1 != o2 && o3 != o4) return true;

        // Special cases (colinear cases)
        if (o1 == COLINEAR && contains(other.a)) return true;
        if (o2 == COLINEAR && contains(other.b)) return true;
        if (o3 == COLINEAR && other.contains(a)) return true;
        if (o4 == COLINEAR && other.contains(b)) return true;

        return false;
    }

    double distance2_to_point(const Point& point) const {
        double seg_len2 = length_squared();
        if (seg_len2 == 0) return point.dist_squared(a);
        double dot = (point.x - a.x) * (b.x - a.x) + (point.y - a.y) * (b.y - a.y);
        double scale = max(0.0, min(1.0, dot / seg_len2));
        Point projection(a.x + scale * (b.x - a.x), a.y + scale * (b.y - a.y));
        return point.dist_squared(projection);
    }

    double distance_to_segment(const LineSegment& other) const {
        if (intersects(other)) return 0.0;
        return sqrt(min({
            other.distance2_to_point(a),
            other.distance2_to_point(b),
            distance2_to_point(other.a),
            distance2_to_point(other.b)}
        ));
    }
};

int main() {
    FAST_IO;
    int T;
    cin >> T;
    cout << fixed << setprecision(2);

    while (T--) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        LineSegment l1(x1, y1, x2, y2);
        LineSegment l2(x3, y3, x4, y4);

        double dist = l1.distance_to_segment(l2);
        cout << dist << endl;
    }

    return 0;
}
