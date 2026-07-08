#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates
int removeDuplicates(vector<int>& nums) {

    if (nums.size() == 0) {
        return 0;
    }

    int i = 0;

    for (int j = 1; j < nums.size(); j++) {

        // If a new unique element is found
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }

    // Number of unique elements
    return i + 1;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "\nNumber of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}