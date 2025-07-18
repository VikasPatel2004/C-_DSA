#include <iostream>
using namespace std;

int main(){
    char ch ;
    cout << "Enter a character:" <<endl;
    cin >>ch;
    if (ch>='a' && ch<='z') {
        cout << "character is lowercase" <<endl;

    }
    else {
        cout << "character is uppercase" << endl;
    }
    return 0;
};