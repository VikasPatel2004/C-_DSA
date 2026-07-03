#include <iostream>
using namespace std;

double myPow(double x, int n) {

    long long binForm = n;

    // If exponent is negative
    if(binForm < 0) {
        x = 1 / x;
        binForm = -binForm;
    }

    double ans = 1.0;

    while(binForm > 0) {

        if(binForm % 2 == 1) {
            ans *= x;
        }

        x *= x;
        binForm /= 2;
    }

    return ans;
}

int main() {

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout.setf(ios::fixed);
    cout.precision(4);

    cout << "Answer = " << myPow(x, n) << endl;

    return 0;
}