// Question - Pascal's Triangle I
//
// Given row r and column c (1-indexed),
// return the value present at that position
// in Pascal's Triangle.
//
// Formula:
// Value at (r, c) = (r-1) C (c-1)
//
// Example:
// r = 5, c = 3
// => 4C2 = 6

#include <iostream>
using namespace std;

// -------------------------------------------------------------
// Function to calculate nCr
//
// Formula:
// nCr = n! / (r! * (n-r)!)
//
// Optimized approach:
// Instead of calculating factorials separately,
// compute directly to avoid overflow and extra computation.
// -------------------------------------------------------------
int nCr(int n, int r) {

    int res = 1;

    for (int i = 0; i < r; i++) {

        // Multiply numerator part
        res = res * (n - i);

        // Divide denominator part
        res = res / (i + 1);
    }

    return res;
}

// -------------------------------------------------------------
// Function to find value at given row and column
//
// Since indexing is 1-based:
// Pascal[r][c] = (r-1)C(c-1)
// -------------------------------------------------------------
int pascalTriangleI(int r, int c) {

    return nCr(r - 1, c - 1);
}

int main() {

    int r, c;

    cout << "Enter row number: ";
    cin >> r;

    cout << "Enter column number: ";
    cin >> c;

    int ans = pascalTriangleI(r, c);

    cout << "\nValue at row "
         << r
         << " and column "
         << c
         << " is: "
         << ans
         << endl;

    return 0;
}