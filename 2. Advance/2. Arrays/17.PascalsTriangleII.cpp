// Question - Pascal's Triangle II
//
// Given a row number r (1-indexed),
// return all elements present in that row
// of Pascal's Triangle.
//
// Example:
// r = 5
// Output = [1, 4, 6, 4, 1]

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(r)
// Space Complexity: O(r)
//
// Logic:
// Every element in Pascal's row can be generated using:
//
// nCr = previous_element * (n-r) / r
//
// Instead of calculating factorial every time,
// we generate each value from the previous one.
// -------------------------------------------------------------
vector<int> pascalTriangleII(int r) {

    vector<int> ans;

    int res = 1;

    // First element is always 1
    ans.push_back(res);

    // Generate remaining elements
    for (int c = 1; c < r; c++) {

        // Compute next value using previous value
        res = res * (r - c);
        res = res / c;

        ans.push_back(res);
    }

    return ans;
}

int main() {

    int r;

    cout << "Enter row number: ";
    cin >> r;

    vector<int> ans = pascalTriangleII(r);

    cout << "\nPascal Triangle Row " << r << ": ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}