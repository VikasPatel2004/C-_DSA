#include <iostream>
#include <string>
#include <algorithm> // Needed for std::reverse

using namespace std;

int main() {
    string str = "apna college"; // ← semicolon added
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}