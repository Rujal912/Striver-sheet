// Question - Rotate Matrix by 90 Degrees Clockwise
//
// Given an N x N matrix,
// rotate it by 90 degrees clockwise.
//
// Rotation must be done in-place.
//
// Example:
//
// 1 2 3
// 4 5 6
// 7 8 9
//
// After rotation:
//
// 7 4 1
// 8 5 2
// 9 6 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
//
// Logic:
// Create a new matrix.
//
// Formula:
// ans[j][n-1-i] = matrix[i][j]
//
// This maps every element to its rotated position.
// -------------------------------------------------------------
void rotateMatrixBrute(vector<vector<int>>& matrix) {

    int n = matrix.size();

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    // Copy rotated matrix back
    matrix = ans;
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Logic:
// Step 1: Transpose the matrix
// Step 2: Reverse every row
//
// Example:
//
// Original:
// 1 2 3
// 4 5 6
// 7 8 9
//
// After transpose:
// 1 4 7
// 2 5 8
// 3 6 9
//
// After reversing rows:
// 7 4 1
// 8 5 2
// 9 6 3
// -------------------------------------------------------------
void rotateMatrixOptimal(vector<vector<int>>& matrix) {

    int n = matrix.size();

    // -------------------------------------------------
    // Step 1: Transpose matrix
    // Swap matrix[i][j] with matrix[j][i]
    // -------------------------------------------------
    for (int i = 0; i <= n - 2; i++) {

        for (int j = i + 1; j < n; j++) {

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // -------------------------------------------------
    // Step 2: Reverse every row
    // -------------------------------------------------
    for (int i = 0; i < n; i++) {

        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to print matrix
void printMatrix(vector<vector<int>>& matrix) {

    for (auto row : matrix) {

        for (auto val : row) {

            cout << val << " ";
        }

        cout << endl;
    }
}

int main() {

    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> matrix[i][j];
        }
    }

    // Create copies for both approaches
    vector<vector<int>> bruteMatrix = matrix;
    vector<vector<int>> optimalMatrix = matrix;

    rotateMatrixBrute(bruteMatrix);
    rotateMatrixOptimal(optimalMatrix);

    cout << "\nBrute Result:\n";
    printMatrix(bruteMatrix);

    cout << "\nOptimal Result:\n";
    printMatrix(optimalMatrix);

    return 0;
}