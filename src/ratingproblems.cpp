#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int sum_given = 0;
    int rating;
    
    for (int i = 0; i < k; i++) {
        cin >> rating;
        sum_given += rating;
    }
    
    double min_rating = (sum_given + (n - k) * (-3)) / (double)n;
    double max_rating = (sum_given + (n - k) * 3) / (double)n;
    
    cout << fixed << setprecision(6) << min_rating << " " << max_rating << endl;
    
    return 0;
}
