#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Compare two frequency arrays
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    // Check if s1's permutation is in s2
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        // Frequency of characters in s1
        for (char c : s1) {
            freq[c - 'a']++;
        }

        int windSize = s1.length();

        for (int i = 0; i <= s2.length() - windSize; i++) {
            int windFreq[26] = {0};

            // Build frequency for current window
            for (int j = 0; j < windSize; j++) {
                windFreq[s2[i + j] - 'a']++;
            }

            // Compare with s1 frequency
            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};

// Main function to test the logic
int main() {
    Solution sol;
    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    bool result = sol.checkInclusion(s1, s2);

    if (result) {
        cout << "Permutation of s1 is present in s2." << endl;
    } else {
        cout << "No permutation of s1 found in s2." << endl;
    }

    return 0;
}