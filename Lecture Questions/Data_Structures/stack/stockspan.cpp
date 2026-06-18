#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // Example input prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // Initialize answer vector and stack
    vector<int> ans(price.size(), 0);
    stack<int> s;

    // Compute span for each day
    for (int i = 0; i < price.size(); i++) {
        // Pop smaller or equal previous prices
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        // If stack empty → all previous prices smaller
        if (s.empty()) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top(); // distance from previous higher price
        }

        // Push current index
        s.push(i);
    }

    // Print result
    cout << "Stock Span values: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
