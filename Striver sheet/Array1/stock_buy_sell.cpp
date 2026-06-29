#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0; i < prices.size(); i++) {

        // Update minimum buying price
        minPrice = min(minPrice, prices[i]);

        // Calculate profit if sold today
        int profit = prices[i] - minPrice;

        // Update maximum profit
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int ans = maxProfit(prices);

    cout << "Maximum Profit = " << ans << endl;

    return 0;
}