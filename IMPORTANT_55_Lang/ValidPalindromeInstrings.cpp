#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {

    int n = s.length();

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int i = 0;
    int j = n - 1;

    while(i <= j) {

        if(!isalnum(s[i])) {
            i++;
        }
        else if(!isalnum(s[j])) {
            j--;
        }
        else if(s[i] == s[j]) {
            i++;
            j--;
        }
        else {
            return false;
        }
    }

    return true;
}

int main() {

    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome(s)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}