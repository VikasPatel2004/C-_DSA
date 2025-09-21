#include <iostream>
using namespace std;

// Function to perform linear search in a 2D array
int LinearSearch(int mat[][3], int row, int col, int key) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == key) {
                return i * col + j; // Return linear index
            }
        }
    }
    return -1; // Key not found
}

int main() {
    const int row = 3, col = 3;
    int mat[row][col] = {
        {1, 2, 3},
        {4, 5, 6},   // as we cant send cin in loop for function 
        {7, 8, 9}
    };

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int result = LinearSearch(mat, row, col, key);

    if (result != -1)
        cout << "Key found at linear index: " << result << endl;
    else
        cout << "Key not found in the matrix." << endl;

    return 0;
}