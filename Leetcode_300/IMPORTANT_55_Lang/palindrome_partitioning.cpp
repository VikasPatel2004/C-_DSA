#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool isPalin(string str) {

        int i = 0;
        int j = str.size() - 1;

        while(i < j) {

            if(str[i] != str[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void getAllParts(string s,
                     vector<string>& partitions,
                     vector<vector<string>>& ans) {

        // Base Case
        if(s.size() == 0) {

            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if(isPalin(part)) {

                partitions.push_back(part);

                getAllParts(
                    s.substr(i + 1),
                    partitions,
                    ans
                );

                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(
            s,
            partitions,
            ans
        );

        return ans;
    }
};

int main() {

    Solution s;

    string str = "aab";

    vector<vector<string>> ans = s.partition(str);

    cout << "Palindrome Partitions are:\n";

    for(auto vec : ans) {

        cout << "[ ";

        for(auto word : vec) {
            cout << word << " ";
        }

        cout << "]\n";
    }

    return 0;
}