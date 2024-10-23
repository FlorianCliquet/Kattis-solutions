#include <bits/stdc++.h>

#define EPS 0.0001
#define PI 3.141599 // A rough overestimate of PI

using namespace std;

typedef struct _line_ {
    double x0; // x-coordinate of the starting point of the line
    double dx; // x-direction component of the line vector
    double y0; // y-coordinate of the starting point of the line
    double dy; // y-direction component of the line vector
} LINE;

double A[2], B[2], C[2]; // Coordinates of points A, B, C (the triangle vertices)
double P[2]; // Coordinates of the Brocard point
double AB[2], BC[2], CA[2]; // Unit vectors for triangle sides AB, BC, CA
double AP[2], BP[2], CP[2]; // Unit vectors for Brocard direction lines from A, B, C

/*
Goal: Find the intersection point between two parametric lines.
Formula:
    Line 1: x = x0 + t * dx, y = y0 + t * dy
    Line 2: x = x1 + s * dx2, y = y1 + s * dy2
    Solving for t when the two lines intersect:
    (x0 + t * dx1) = (x1 + s * dx2) and (y0 + t * dy1) = (y1 + s * dy2)
*/
int LineInter(LINE* pl1, LINE* pl2, double* pres) {
    double num, denom, t;
    denom = pl1->dx * pl2->dy - pl1->dy * pl2->dx; // Denominator for solving the line intersection
    if (fabs(denom) < EPS) return -3; // Lines are parallel
    num = (pl2->x0 - pl1->x0) * pl2->dy - (pl2->y0 - pl1->y0) * pl2->dx;
    t = num / denom; // Solving for parameter t
    pres[0] = pl1->x0 + t * pl1->dx; // x-coordinate of intersection point
    pres[1] = pl1->y0 + t * pl1->dy; // y-coordinate of intersection point
    return 0;
}

/*
Goal: Normalize the vectors AB, BC, and CA to make them unit vectors.
Formula:
    Normalize a vector v = (vx, vy):
    magnitude = sqrt(vx^2 + vy^2)
    normalized vector = (vx / magnitude, vy / magnitude)
*/
int MakeUnitVects() {
    double norm, denom;

    // Normalize AB
    AB[0] = B[0] - A[0]; // x-component of vector AB
    AB[1] = B[1] - A[1]; // y-component of vector AB
    norm = AB[0] * AB[0] + AB[1] * AB[1]; // Length of AB^2
    if (norm < EPS) return -1;
    denom = 1.0 / sqrt(norm); // Magnitude of AB
    AB[0] *= denom; // Normalize x-component
    AB[1] *= denom; // Normalize y-component

    // Normalize BC
    BC[0] = C[0] - B[0];
    BC[1] = C[1] - B[1];
    norm = BC[0] * BC[0] + BC[1] * BC[1];
    if (norm < EPS) return -1;
    denom = 1.0 / sqrt(norm);
    BC[0] *= denom;
    BC[1] *= denom;

    // Normalize CA
    CA[0] = A[0] - C[0];
    CA[1] = A[1] - C[1];
    norm = CA[0] * CA[0] + CA[1] * CA[1];
    if (norm < EPS) return -1;
    denom = 1.0 / sqrt(norm);
    CA[0] *= denom;
    CA[1] *= denom;

    // Check if the points are collinear (i.e., the vectors are parallel)
    if (fabs(AB[0] * CA[1] - AB[1] * CA[0]) < EPS) return -2;
    if (fabs(BC[0] * AB[1] - BC[1] * AB[0]) < EPS) return -2;
    if (fabs(CA[0] * BC[1] - CA[1] * BC[0]) < EPS) return -2;

    return 0;
}

/*
Goal: Calculate the Brocard angle using the formula for cotangent and find the Brocard point.
Formula:
    cot(ω) = cot(A) + cot(B) + cot(C)
    Brocard angle ω = atan2(1.0, cot(ω))

    For each vertex A, B, and C, compute the direction of the Brocard line:
    AP = Rotate AB by the Brocard angle ω (same for BP and CP)

    Intersect the lines to compute the Brocard point coordinates.
*/
int BrocardFormula() {
    double cotA, cotB, cotC, cotP, BrocAng, c, s;
    LINE l1, l2, l3;
    double PAB[2], PBC[2], PCA[2];

    if (MakeUnitVects() != 0) return -1;

    // Compute cotangents of angles A, B, C
    cotA = (AB[0] * CA[0] + AB[1] * CA[1]) / (AB[0] * CA[1] - AB[1] * CA[0]);
    cotB = (AB[0] * BC[0] + AB[1] * BC[1]) / (BC[0] * AB[1] - BC[1] * AB[0]);
    cotC = (BC[0] * CA[0] + BC[1] * CA[1]) / (CA[0] * BC[1] - CA[1] * BC[0]);

    // Sum of cotangents to get the cotangent of the Brocard angle
    cotP = cotA + cotB + cotC;
    BrocAng = atan2(1.0, cotP); // Brocard angle in radians
    c = cos(BrocAng);
    s = sin(BrocAng);

    // Compute the direction of the Brocard lines from A, B, C
    AP[0] = AB[0] * c - AB[1] * s; // Rotate vector AB by the Brocard angle
    AP[1] = AB[0] * s + AB[1] * c;
    l1.x0 = A[0]; l1.y0 = A[1]; l1.dx = AP[0]; l1.dy = AP[1];

    BP[0] = BC[0] * c - BC[1] * s;
    BP[1] = BC[0] * s + BC[1] * c;
    l2.x0 = B[0]; l2.y0 = B[1]; l2.dx = BP[0]; l2.dy = BP[1];

    CP[0] = CA[0] * c - CA[1] * s;
    CP[1] = CA[0] * s + CA[1] * c;
    l3.x0 = C[0]; l3.y0 = C[1]; l3.dx = CP[0]; l3.dy = CP[1];

    // Find the intersection points of the Brocard lines
    if (LineInter(&l1, &l2, &PAB[0]) != 0) return -4;
    if (LineInter(&l2, &l3, &PBC[0]) != 0) return -4;
    if (LineInter(&l3, &l1, &PCA[0]) != 0) return -4;

    // Average of intersection points gives the Brocard point
    P[0] = (PAB[0] + PBC[0] + PCA[0]) / 3.0;
    P[1] = (PAB[1] + PBC[1] + PCA[1]) / 3.0;

    return 0;
}

int main() {
    int t; cin >> t; // Number of test cases
    while(t--){
        double n; cin >> n >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1]; // Input for each test case

        // Compute Brocard point
        int ret = BrocardFormula();

        if (ret != 0) {
            cout << "Error: " << ret << endl;
            return 1;
        }

        // Output Brocard point with high precision
        cout << n << " " << setprecision(20) << P[0] << " " << P[1] << endl;
    }
    return 0;
}
