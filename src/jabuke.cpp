#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

// Fast input function to quickly read integers using getchar()
inline int fast_input() {
    int x = 0;
    char c;

    // Skip non-numeric characters, check for EOF
    while ((c = getchar()) != EOF && (c < '0' || c > '9'));

    // If we hit EOF, return a signal (e.g., -1)
    if (c == EOF) return -1;

    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

// Function to calculate the area of a triangle given by three points
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

int main() {
    FAST_IO;

    double area = 0.0;
    int area_points[6] = {0, 0, 0, 0, 0, 0}; // x1, y1, x2, y2, x3, y3

    // Reading triangle vertices
    for (int i = 0; i < 6; i++) {
        area_points[i] = fast_input();
    }

    // Calculate the area of the triangle
    area = triangle_area(area_points[0], area_points[1],
                         area_points[2], area_points[3],
                         area_points[4], area_points[5]);

    int n = fast_input();
    int count = 0;

    // Counting points within the triangle
    while (n--) {
        int px = fast_input();
        int py = fast_input();

        // Calculate area of triangles formed with the point
        double area1 = triangle_area(px, py, area_points[2], area_points[3], area_points[4], area_points[5]);
        double area2 = triangle_area(area_points[0], area_points[1], px, py, area_points[4], area_points[5]);
        double area3 = triangle_area(area_points[0], area_points[1], area_points[2], area_points[3], px, py);

        // Check if the sum of areas equals the area of the triangle
        if (area == area1 + area2 + area3) {
            count++;
        }
    }

    cout << fixed << setprecision(1) << area << endl;
    cout << count << endl;

    return 0;
}
