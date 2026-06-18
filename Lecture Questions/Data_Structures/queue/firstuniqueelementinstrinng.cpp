#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        queue<int> q;   // stores indexes
        unordered_map<char, int> m;

        // Traverse the string
        for(int i = 0; i <= s.size() - 1; i++) {

            // If character appears first time
            if(m.find(s[i]) == m.end()) {
                q.push(i);
            }

            // Increase frequency
            m[s[i]]++;
        }

        // Remove repeated characters from front
        while(q.size() > 0 && m[s[q.front()]] > 1) {
            q.pop();
        }

        // If no unique character
        if(q.empty()) {
            return -1;
        }
        else {
            return q.front();
        }
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    int ans = obj.firstUniqChar(s);

    cout << "First unique character index: " << ans << endl;

    return 0;
}