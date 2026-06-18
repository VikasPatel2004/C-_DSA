#include <iostream>
#include <vector>
using namespace std;

void solve(int index,
           vector<int>& arr,
           vector<int>& subset)
{
    if(index == arr.size())
    {
        cout << "{ ";

        for(int x : subset)
            cout << x << " ";

        cout << "}" << endl;

        return;
    }

    // Include
    subset.push_back(arr[index]);

    solve(index + 1, arr, subset);

    // Backtrack
    subset.pop_back();

    // Exclude
    solve(index + 1, arr, subset);
}

int main()
{
    vector<int> arr = {1,2,3};

    vector<int> subset;

    solve(0, arr, subset);
}