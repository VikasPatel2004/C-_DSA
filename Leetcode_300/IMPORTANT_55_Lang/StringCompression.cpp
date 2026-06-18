#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {

    int n = chars.size();

    int i = 0;
    int j = 0;

    while(i < n) {

        char current = chars[i];
        int count = 0;

        while(i < n && chars[i] == current) {
            count++;
            i++;
        }

        chars[j++] = current;

        if(count > 1) {

            string freq = to_string(count);

            for(char ch : freq) {
                chars[j++] = ch;
            }
        }
    }

    return j;
}

int main() {

    vector<char> chars =
    {'a','a','b','b','c','c','c'};

    int len = compress(chars);

    cout << "Length = " << len << endl;

    cout << "Compressed Array: ";

    for(int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}