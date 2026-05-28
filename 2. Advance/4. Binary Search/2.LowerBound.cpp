// ======================================================
// Lower Bound
//
// Find first index such that:
// nums[index] >= x
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

int lowerBoundBrute(
    vector<int>& nums,
    int x
) {

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        // First element >= x
        if(nums[i] >= x) {
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
// Search for smallest index
// having value >= x
// ------------------------------------------------------

int lowerBoundOptimal(
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
        if(nums[mid] >= x) {

            ans = mid;

            // Search on left side
            // for smaller index
            high = mid - 1;
        }

        else {

            // Search right half
            low = mid + 1;
        }
    }

    return ans;
}




// ------------------------------------------------------
// STL Approach
//
// lower_bound returns iterator
//
// Convert iterator → index
// by subtracting begin()
// ------------------------------------------------------

int lowerBoundSTL(
    vector<int>& nums,
    int x
) {

    return
        lower_bound(
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
        << lowerBoundBrute(nums, x);

    cout
        << "\nOptimal Result: "
        << lowerBoundOptimal(nums, x);

    cout
        << "\nSTL Result: "
        << lowerBoundSTL(nums, x);

    return 0;
}