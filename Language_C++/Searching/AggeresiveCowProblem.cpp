#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:

    bool isPossible(vector<int>& stalls,
                    int cows,
                    int minDist) {

        int count = 1;

        int lastPos = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {

            if(stalls[i] - lastPos >= minDist) {

                count++;

                lastPos = stalls[i];

                if(count == cows)
                    return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int>& stalls,
                       int cows) {

        sort(stalls.begin(), stalls.end());

        int st = 1;

        int end = stalls.back() - stalls.front();

        int ans = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isPossible(stalls, cows, mid)) {

                ans = mid;

                st = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> stalls = {1,2,4,8,9};

    cout << s.aggressiveCows(stalls, 3);

    return 0;
}