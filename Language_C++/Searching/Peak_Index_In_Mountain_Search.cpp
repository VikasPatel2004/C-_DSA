#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1;
        int end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (arr[mid] < arr[mid + 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // Shouldn't be reached for valid mountain arrays
    }
};

int main() {
    vector<int> mountainArray = {1, 3, 8, 12, 4, 2};
    Solution obj;
    int peakIndex = obj.peakIndexInMountainArray(mountainArray);

    if (peakIndex != -1) {
        cout << "Peak found at index: " << peakIndex << endl;
        cout << "Peak value: " << mountainArray[peakIndex] << endl;
    } else {
        cout << "No peak found in the array." << endl;
    }

    return 0;
}