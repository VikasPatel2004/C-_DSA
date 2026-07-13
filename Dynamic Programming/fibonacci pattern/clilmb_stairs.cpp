#include <bits/stdc++.h>
using namespace std;

// -------------------- Tabulation (Bottom-Up DP) --------------------
class SolutionTab {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// -------------------- Recursion --------------------
class SolutionRec {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// -------------------- Memoization (Top-Down DP) --------------------
class SolutionMemo {
public:
    int helper(int n, vector<int> &dp) {
        if (n == 1 || n == 2) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

// -------------------- Driver Code --------------------
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    SolutionTab solTab;
    SolutionRec solRec;
    SolutionMemo solMemo;

    cout << "Tabulation result: " << solTab.climbStairs(n) << endl;
    cout << "Recursion result: " << solRec.climbStairs(n) << endl;
    cout << "Memoization result: " << solMemo.climbStairs(n) << endl;

    return 0;
}
