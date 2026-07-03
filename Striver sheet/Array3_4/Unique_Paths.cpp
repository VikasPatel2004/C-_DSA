#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {

    int N = m + n - 2;

    int r = min(m - 1, n - 1);

    double ans = 1;

    for(int i = 1; i <= r; i++) {

        ans = ans * (N - r + i);

        ans = ans / i;
    }

    return (int)ans;
}

int main() {

    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    cout << "Unique Paths = "
         << uniquePaths(m, n);

    return 0;
}