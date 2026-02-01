#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate area between left and right
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            int area = width * minHeight;

            maxWater = max(maxWater, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum water container = " << sol.maxArea(height) << endl;

    return 0;
}