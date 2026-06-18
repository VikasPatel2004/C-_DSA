#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {

    vector<string> words;
    string word = "";

    for(char ch : s) {

        if(ch != ' ') {

            word += ch;
        }
        else {

            if(word != "") {

                words.push_back(word);
                word = "";
            }
        }
    }

    // Store the last word
    if(word != "") {

        words.push_back(word);
    }

    string ans = "";

    for(int i = words.size() - 1; i >= 0; i--) {

        ans += words[i];

        if(i != 0) {

            ans += " ";
        }
    }

    return ans;
}

int main() {

    string s = "  hello   world  ";

    cout << reverseWords(s);

    return 0;
}