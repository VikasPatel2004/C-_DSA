#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7}; // You can modify this as needed

    int maxwater = 0;
    int lp = 0;
    int rp = height.size() - 1;

    while (lp < rp) {
        int width = rp - lp;
        int h = min(height[lp], height[rp]);
        int currwater = width * h;
        maxwater = max(maxwater, currwater);

        height[lp] < height[rp] ? lp++ : rp--;
    }

    cout << "Maximum water area: " << maxwater << endl;
    return 0;
}