#include <iostream>
#include <string>
using namespace std;

bool isAlphaNum(char ch) {
    return (ch >= '0' && ch <= '9') || 
           (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}

bool Valid_Palindrome(string s) {
    int st = 0;
    int end = s.length() - 1;

    while (st < end) {
        if (!isAlphaNum(s[st])) {
            st++;
            continue;
        }
        if (!isAlphaNum(s[end])) {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main() {
    string s = "Madam";
    bool check = Valid_Palindrome(s);
    if (check) {
        cout << "It is a valid palindrome";
    } else {
        cout << "It is not a valid palindrome";
    }
    return 0;
}