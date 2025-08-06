#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false;
        }
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return students <= m;
}

int BookAllocation(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int start = 0, end = sum;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 5};
    int n = arr.size();
    int m = 2;
    cout << "Minimum number of pages: " << BookAllocation(arr, n, m) << endl;
    return 0;
}