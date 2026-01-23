// Question - Largest Element in an Array
// We need to find the maximum element present in the array.
// The array may contain negative numbers and duplicates.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n log n)
// Logic:
// 1. Sort the array
// 2. The last element will be the largest
// -------------------------------------------------------------
int largestElementBrute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - 1];
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// 1. Assume first element is the maximum
// 2. Traverse the array and update maximum whenever a larger value is found
// -------------------------------------------------------------
int largestElementOptimal(vector<int>& nums) {
    int maxi = nums[0];   // Initialize with first element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maxi) {
            maxi = nums[i];
        }
    }

    return maxi;
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

    // Copy array for brute approach to avoid modifying original
    vector<int> numsCopy = nums;

    int bruteAns = largestElementBrute(numsCopy);
    int optAns   = largestElementOptimal(nums);

    cout << "\nBrute Force Result: " << bruteAns << endl;
    cout << "Optimal Result: " << optAns << endl;

    return 0;
}
