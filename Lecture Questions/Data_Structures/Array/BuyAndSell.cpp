#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 6;
    int arr[] = {7, 5, 1, 6, 4, 2};
    int maxProfit = 0;
    int bestBuy = arr[0];

    for(int i = 0; i < n; i++) {
        bestBuy = min(bestBuy, arr[i]);
        maxProfit = max(maxProfit, arr[i] - bestBuy);
    }

    if(maxProfit == 0) {
        cout << "Profit is not possible." << endl;
    } else {
        cout << "Max profit: " << maxProfit << endl;
        cout << "Best buy price: " << bestBuy << endl;
    }

    return 0;
}