#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    if(n > m) {
        return false;
    }

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    // Store frequency of s1
    for(char ch : s1) {
        freq1[ch - 'a']++;
    }

    // Store frequency of first window of s2
    for(int i = 0; i < n; i++) {
        freq2[s2[i] - 'a']++;
    }

    // Check first window
    if(freq1 == freq2) {
        return true;
    }

    // Sliding Window
    for(int i = n; i < m; i++) {

        // Add new character entering the window
        freq2[s2[i] - 'a']++;

        // Remove old character leaving the window
        freq2[s2[i - n] - 'a']--;

        // Compare frequencies
        if(freq1 == freq2) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1 = "ab";
    string s2 = "eidbaooo";

    if(checkInclusion(s1, s2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}