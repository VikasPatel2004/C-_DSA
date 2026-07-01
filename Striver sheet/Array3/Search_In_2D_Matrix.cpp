#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = m * n - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int row = mid / n;
        int col = mid % n;

        if(matrix[row][col] == target) {

            return true;
        }

        else if(matrix[row][col] < target) {

            low = mid + 1;
        }

        else {

            high = mid - 1;
        }
    }

    return false;
}

int main() {

    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            cin >> matrix[i][j];
        }
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    if(searchMatrix(matrix, target)) {

        cout << "Target Found";
    }
    else {

        cout << "Target Not Found";
    }

    return 0;
}