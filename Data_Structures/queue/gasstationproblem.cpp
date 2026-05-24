#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        int totalCost = 0;

        // Calculate total gas
        for(int val : gas) {
            totalGas += val;
        }

        // Calculate total cost
        for(int val : cost) {
            totalCost += val;
        }

        // If journey is impossible
        if(totalGas < totalCost) {
            return -1;
        }

        int currGas = 0;
        int start = 0;

        // Find starting index
        for(int i = 0; i < gas.size(); i++) {

            currGas += gas[i] - cost[i];

            // Cannot move ahead
            if(currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        return start;
    }
};

int main() {

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    Solution obj;

    int ans = obj.canCompleteCircuit(gas, cost);

    cout << "Starting Index: " << ans << endl;

    return 0;
}