#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {

    int low = 0;
    int high = nums.size() - 1;
    int mid = low;

    while(mid <= high) {

        if(nums[mid] == 0) {

            swap(nums[low], nums[mid]);

            low++;
            mid++;
        }

        else if(nums[mid] == 1) {

            mid++;
        }

        else {

            swap(nums[high], nums[mid]);

            // Don't increment mid here because
            // the element coming from the high side
            // has not been processed yet.

            high--;
        }
    }
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (only 0, 1 and 2): ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}