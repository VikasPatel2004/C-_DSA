#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpan {
public:
    vector<int> calculateSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> span(n); 
        stack<int> st; // stores indices

        // First day's span is always 1
        span[0] = 1;
        st.push(0);

        for (int i = 1; i < n; i++) {
            // Pop elements smaller or equal to current price
            while (!st.empty() && prices[st.top()] <= prices[i]) {
                st.pop();
            }

            // If stack empty, all previous prices are smaller
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());

            st.push(i);
        }

        return span;
    }
};

int main() {
    StockSpan ss;
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> result = ss.calculateSpan(prices);

    cout << "Stock spans: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
