// ======================================================
// Upper Bound
//
// Find first index such that:
// nums[index] > x
//
// If not found return nums.size()
// ======================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// ------------------------------------------------------
// Brute Force
//
// TC → O(n)
// SC → O(1)
//
// Traverse array linearly
// ------------------------------------------------------

int upperBoundBrute(
    vector<int>& nums,
    int x
) {

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        // First element > x
        if(nums[i] > x) {
            return i;
        }
    }

    // No valid index found
    return n;
}




// ------------------------------------------------------
// Optimal → Binary Search
//
// TC → O(log n)
// SC → O(1)
//
// Find smallest index
// having value > x
// ------------------------------------------------------

int upperBoundOptimal(
    vector<int>& nums,
    int x
) {

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    int ans = n;

    while(low <= high) {

        int mid =
            low + (high - low) / 2;

        // Possible answer found
        if(nums[mid] > x) {

            ans = mid;

            // Search left side
            // for smaller valid index
            high = mid - 1;
        }

        else {

            // Search right side
            low = mid + 1;
        }
    }

    return ans;
}




// ------------------------------------------------------
// STL Approach
//
// upper_bound returns iterator
//
// Convert iterator → index
// by subtracting begin()
// ------------------------------------------------------

int upperBoundSTL(
    vector<int>& nums,
    int x
) {

    return
        upper_bound(
            nums.begin(),
            nums.end(),
            x
        ) - nums.begin();
}




int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int x;

    cout << "Enter x: ";
    cin >> x;

    cout
        << "\nBrute Result: "
        << upperBoundBrute(nums, x);

    cout
        << "\nOptimal Result: "
        << upperBoundOptimal(nums, x);

    cout
        << "\nSTL Result: "
        << upperBoundSTL(nums, x);

    return 0;
}