#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double v, a, t;
    cin >> v >> a >> t;
    
    double d = v * t + 0.5 * a * t * t;
    
    cout << fixed << setprecision(10) << d << endl;
    
    return 0;
}
