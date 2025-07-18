#include <iostream>
using namespace std;

int min_of_two(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a, b;
    cout << "Enter first numbers: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    int min = min_of_two(a, b);
    cout << "Minimum of two numbers is: " << min << endl;
}