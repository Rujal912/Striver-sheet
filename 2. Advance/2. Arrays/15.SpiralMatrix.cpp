// Question - Print Matrix in Spiral Manner
//
// Given an M x N matrix,
// print all elements in clockwise spiral order.
//
// Example:
// 1 2 3
// 4 5 6
// 7 8 9
//
// Spiral Order:
// 1 2 3 6 9 8 7 4 5

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n * m)
// Space Complexity: O(1) excluding output array
//
// Logic:
// Use 4 boundaries:
// top, bottom, left, right
//
// Traverse in 4 directions:
// 1. Left → Right
// 2. Top → Bottom
// 3. Right → Left
// 4. Bottom → Top
//
// Shrink boundaries after every traversal.
// -------------------------------------------------------------
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int n = matrix.size();       // Number of rows
    int m = matrix[0].size();    // Number of columns

    // Boundaries
    int left = 0;
    int right = m - 1;
    int top = 0;
    int bottom = n - 1;

    vector<int> ans;

    // Continue until boundaries cross
    while (top <= bottom && left <= right) {

        // -------------------------------------------------
        // Traverse Left → Right
        // -------------------------------------------------
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }

        top++;

        // -------------------------------------------------
        // Traverse Top → Bottom
        // -------------------------------------------------
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }

        right--;

        // -------------------------------------------------
        // Traverse Right → Left
        // Important condition:
        // Prevent duplicate printing when only one row remains
        // -------------------------------------------------
        if (top <= bottom) {

            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // -------------------------------------------------
        // Traverse Bottom → Top
        // Important condition:
        // Prevent duplicate printing when only one column remains
        // -------------------------------------------------
        if (left <= right) {

            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    return ans;
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    cout << "\nSpiral Order: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}