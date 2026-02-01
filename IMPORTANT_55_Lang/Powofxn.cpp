#include <iostream>
#include <iomanip>   // for fixed and setprecision
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Handle base cases
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        long binform = n;  // use long to avoid overflow
        if (n < 0) {
            x = 1 / x;         // reciprocal for negative powers
            binform = -binform;
        }

        double ans = 1.0;
        while (binform > 0) {
            if (binform % 2 == 1) {
                ans *= x;      // multiply when current bit is 1
            }
            x *= x;            // square the base
            binform /= 2;      // move to next bit
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Format output: fixed-point, no scientific notation
    cout << fixed << setprecision(6);

    // Test cases
    cout << "2^10 = " << sol.myPow(2, 10) << endl;      // Expected 1024
    cout << "2^-3 = " << sol.myPow(2, -3) << endl;      // Expected 0.125
    cout << "3^13 = " << sol.myPow(3, 13) << endl;      // Expected 1594323
    cout << "(-1)^5 = " << sol.myPow(-1, 5) << endl;    // Expected -1
    cout << "(-1)^6 = " << sol.myPow(-1, 6) << endl;    // Expected 1

    return 0;
}