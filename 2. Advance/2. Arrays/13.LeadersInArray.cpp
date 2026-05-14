// Question - Leaders in an Array
// A leader is an element that is strictly greater
// than all elements to its right.
//
// The rightmost element is always a leader.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1) excluding output
//
// Logic:
// For every element, check all elements to its right.
// If no greater or equal element exists, it is a leader.
// -------------------------------------------------------------
vector<int> leadersBrute(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {

        bool leader = true;

        // Check all elements to the right
        for (int j = i + 1; j < n; j++) {

            if (nums[i] <= nums[j]) {
                leader = false;
                break;
            }
        }

        // If still true → leader found
        if (leader == true) {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1) excluding output
//
// Logic:
// Traverse from right side.
// Keep track of maximum element seen so far.
// If current element > maximum, it is a leader.
// -------------------------------------------------------------
vector<int> leadersOptimal(vector<int>& nums) {

    int n = nums.size();

    int maxi = INT_MIN;

    vector<int> ans;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Current element is greater than all right elements
        if (nums[i] > maxi) {

            maxi = nums[i];
            ans.push_back(nums[i]);
        }
    }

    // We traversed from right to left,
    // so reverse to restore original order
    reverse(ans.begin(), ans.end());

    return ans;
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

    vector<int> bruteAns = leadersBrute(nums);
    vector<int> optimalAns = leadersOptimal(nums);

    cout << "\nBrute Result: ";

    for (int x : bruteAns) {
        cout << x << " ";
    }

    cout << "\nOptimal Result: ";

    for (int x : optimalAns) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}