// Question - Move Zeros to End
// Move all 0's to the end of the array while maintaining
// the relative order of non-zero elements.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
// Logic:
// 1. Store all non-zero elements in a temporary array
// 2. Copy them back to original array
// 3. Fill remaining positions with 0
// -------------------------------------------------------------
void moveZeroesBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;

    // Collect non-zero elements
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    // Copy non-zero elements back
    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }

    // Fill remaining positions with zero
    for (int i = temp.size(); i < n; i++) {
        nums[i] = 0;
    }
}

// -------------------------------------------------------------
// Optimal Approach – Version 1 (First zero index)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// 1. Find the first index j where nums[j] == 0
// 2. Traverse from j+1 and swap non-zero elements with nums[j]
// -------------------------------------------------------------
void moveZeroesOptimal1(vector<int>& nums) {
    int n = nums.size();
    int j = -1;

    // Find first zero
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    // No zero found → array already valid
    if (j == -1) return;

    // Swap non-zero elements ahead with zero position
    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

// -------------------------------------------------------------
// Optimal Approach – Version 2 (Two-pointer clean approach)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// 1. j tracks the position to place the next non-zero
// 2. Traverse array and swap non-zero elements forward
// -------------------------------------------------------------
void moveZeroesOptimal2(vector<int>& nums) {
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Copies for different approaches
    vector<int> bruteArr = nums;
    vector<int> opt1Arr  = nums;
    vector<int> opt2Arr  = nums;

    moveZeroesBrute(bruteArr);
    moveZeroesOptimal1(opt1Arr);
    moveZeroesOptimal2(opt2Arr);

    cout << "\nBrute Result: ";
    for (int x : bruteArr) cout << x << " ";

    cout << "\nOptimal v1 Result: ";
    for (int x : opt1Arr) cout << x << " ";

    cout << "\nOptimal v2 Result: ";
    for (int x : opt2Arr) cout << x << " ";

    cout << endl;
    return 0;
}
