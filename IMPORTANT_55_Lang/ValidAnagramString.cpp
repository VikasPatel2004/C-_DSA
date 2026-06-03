#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if(s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> mp;

    for(char ch : s) {
        mp[ch]++; // increase frequency
    }

    for(char ch : t) {
        mp[ch]--; // decrease frequency
    }

    for(auto x : mp) { // x is a pair<char,int>

        if(x.second != 0) { // frequency should become 0
            return false;
        }
    }

    return true;
}

int main() {

    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s, t)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}