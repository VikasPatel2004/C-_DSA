#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0; // 360/60
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5; // 360/12 + extra
        double diff = fabs(hourAngle - minuteAngle);
        return min(diff, 360.0 - diff);
    }
};

int main() {
    Solution sol;
    cout << sol.angleClock(12, 30) << endl; // 165
    cout << sol.angleClock(3, 30) << endl;  // 75
    cout << sol.angleClock(3, 15) << endl;  // 7.5
    return 0;
}
