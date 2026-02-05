#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store last index of each character
        vector<int> lastIndex(256, -1);

        int maxLen = 0;
        int start = 0; // left boundary of current window

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If character was seen inside current window, move start
            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }

            // Update last seen index of current character
            lastIndex[c] = i;

            // Update max length of window
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "ppwekkkewe";

    cout << "Input: " << s1 << " -> Output: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << sol.lengthOfLongestSubstring(s3) << endl;
    cout << "Input: " << s4 << " -> Output: " << sol.lengthOfLongestSubstring(s4) << endl;

    return 0;
}