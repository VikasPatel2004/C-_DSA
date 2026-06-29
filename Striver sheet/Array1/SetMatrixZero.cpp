#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    // Marker arrays
    vector<bool> rowZero(m, false);
    vector<bool> colZero(n, false);

    // Step 1: Traverse the matrix and mark rows & columns
    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            if(matrix[i][j] == 0) {

                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }

    // Step 2: Make the marked rows and columns zero
    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            if(rowZero[i] || colZero[j]) {

                matrix[i][j] = 0;
            }
        }
    }
}

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the matrix:\n";

    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";

    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}