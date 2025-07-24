#include <vector>
using namespace std;

// Finds the candidate for majority element
int findMajorityElement(const vector<int>& nums) {
    int freq = 0;
    int candidate = 0;
    
    for (int num : nums) {
        if (freq == 0) {
            candidate = num;
        }
        freq += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}


#include <iostream>

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << findMajorityElement(nums) << endl;
    return 0;
}