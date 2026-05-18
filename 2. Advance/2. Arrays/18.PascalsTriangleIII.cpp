// Question - Pascal's Triangle III
//
// Given an integer n,
// return the first n rows of Pascal's Triangle.
//
// Example:
// n = 5
//
// Output:
// [
//   [1],
//   [1,1],
//   [1,2,1],
//   [1,3,3,1],
//   [1,4,6,4,1]
// ]

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Function to generate a single row of Pascal's Triangle
//
// Logic:
// Each row follows nCr pattern.
//
// Example for row = 5:
// 1
// 1 * 4 / 1 = 4
// 4 * 3 / 2 = 6
// 6 * 2 / 3 = 4
// 4 * 1 / 4 = 1
//
// Result:
// [1, 4, 6, 4, 1]
// -------------------------------------------------------------
vector<int> generateRow(int row) {

    long long ans = 1;

    vector<int> ansRow;

    // First element is always 1
    ansRow.push_back(1);

    // Generate remaining elements
    for (int col = 1; col < row; col++) {

        ans = ans * (row - col);
        ans = ans / col;

        ansRow.push_back(ans);
    }

    return ansRow;
}

// -------------------------------------------------------------
// Function to generate complete Pascal's Triangle
//
// For every row from 1 to n:
// generate that row and store it.
// -------------------------------------------------------------
vector<vector<int>> pascalTriangleIII(int n) {

    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++) {

        ans.push_back(generateRow(i));
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    vector<vector<int>> result = pascalTriangleIII(n);

    cout << "\nPascal's Triangle:\n";

    for (auto row : result) {

        for (auto val : row) {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}