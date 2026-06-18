#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:

    bool isValid(vector<int>& boards,
                 int painters,
                 int maxTime) {

        int painterCount = 1;
        int time = 0;

        for(int i = 0; i < boards.size(); i++) {

            if(time + boards[i] <= maxTime) {

                time += boards[i];
            }
            else {

                painterCount++;
                time = boards[i];
            }
        }

        return painterCount <= painters;
    }

    int painterPartition(vector<int>& boards,
                         int painters) {

        int total = 0;
        int maxBoard = 0;

        for(int x : boards) {

            total += x;
            maxBoard = max(maxBoard, x);
        }

        int st = maxBoard;
        int end = total;

        int ans = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isValid(boards, painters, mid)) {

                ans = mid;
                end = mid - 1;
            }
            else {

                st = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> boards = {10,20,30,40};

    int painters = 2;

    cout << "Minimum Time = "
         << s.painterPartition(boards, painters);

    return 0;
}