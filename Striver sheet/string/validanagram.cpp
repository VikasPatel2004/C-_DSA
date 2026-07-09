#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {

    unordered_map<char, int> ms;

    // If lengths are different, they can't be anagrams
    if (s.size() != t.size()) {
        return false;
    }

    // Increase frequency of characters in s
    for (char ch : s) {
        ms[ch]++;
    }

    // Decrease frequency of characters in t
    for (char ch : t) {
        ms[ch]--;
    }

    // Check if all frequencies become zero
    for (auto x : ms) {
        if (x.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "\nStrings are Anagrams." << endl;
    }
    else {
        cout << "\nStrings are NOT Anagrams." << endl;
    }

    return 0;
}