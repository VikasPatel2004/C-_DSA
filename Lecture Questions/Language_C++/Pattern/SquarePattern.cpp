#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    int num = 1;
    int m = 9;

    // Print 1234 in 4 lines square pattern

    // for (int i=1;i<=n;i++) {
    //      for (int j = 1; j<=n ; j++)
    //      {
    //         cout<<j;
    //      }
    //      cout<<endl;
    // }

    // Print 123456789 in 3 lines square pattern

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }

    
    return 0;
};