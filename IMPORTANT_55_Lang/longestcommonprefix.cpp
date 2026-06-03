#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string ans = "";

    for(int i = 0; i < strs[0].size(); i++) {

        char ch = strs[0][i];

        for(int j = 1; j < strs.size(); j++) {

            if(i >= strs[j].size() ||
               strs[j][i] != ch) {

                return ans;
            }
        }

        ans += ch;
    }

    return ans;
}

int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    string ans = longestCommonPrefix(strs);

    cout << "Longest Common Prefix = "
         << ans << endl;

    return 0;
}