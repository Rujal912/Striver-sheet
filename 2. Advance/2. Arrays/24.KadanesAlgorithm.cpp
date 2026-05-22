// Question - Kadane's Algorithm
//
// Given an array,
// find the contiguous subarray
// having the maximum sum.
//
// Example:
// [2,3,5,-2,7,-4]
//
// Output:
// 15
//
// Subarray:
// [2,3,5,-2,7]

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^3)
// Space Complexity: O(1)
//
// Logic:
// Generate every possible subarray
// Calculate sum separately.
// -------------------------------------------------------------
int maxSubArrayBrute(
    vector<int>& nums
) {

    int n = nums.size();

    int maxi = INT_MIN;

    for (
        int i = 0;
        i < n;
        i++
    ) {

        for (
            int j = i;
            j < n;
            j++
        ) {

            int sum = 0;

            for (
                int k = i;
                k <= j;
                k++
            ) {

                sum += nums[k];
            }

            maxi =
                max(
                    maxi,
                    sum
                );
        }
    }

    return maxi;
}

// -------------------------------------------------------------
// Better Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Logic:
// Instead of recalculating sum,
// keep extending current subarray.
// -------------------------------------------------------------
int maxSubArrayBetter(
    vector<int>& nums
) {

    int n = nums.size();

    int maxi = INT_MIN;

    for (
        int i = 0;
        i < n;
        i++
    ) {

        int sum = 0;

        for (
            int j = i;
            j < n;
            j++
        ) {

            sum += nums[j];

            maxi =
                max(
                    maxi,
                    sum
                );
        }
    }

    return maxi;
}

// -------------------------------------------------------------
// Optimal Approach
// Kadane's Algorithm
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Logic:
//
// Keep current running sum.
//
// If sum becomes negative:
// reset to 0.
//
// Why?
// Negative sum can never help
// future subarrays.
// -------------------------------------------------------------
int maxSubArrayOptimal(
    vector<int>& nums
) {

    long long sum = 0;

    long long maxi =
        LONG_MIN;

    for (
        int i = 0;
        i < nums.size();
        i++
    ) {

        // Extend subarray
        sum += nums[i];

        // Update answer
        maxi =
            max(
                maxi,
                sum
            );

        // Negative sum is useless
        if (sum < 0) {

            sum = 0;
        }
    }

    return maxi;
}

int main() {

    int n;

    cout
        << "Enter size: ";

    cin >> n;

    vector<int> nums(n);

    cout
        << "Enter elements: ";

    for (
        int i = 0;
        i < n;
        i++
    ) {

        cin >> nums[i];
    }

    cout
        << "\nBrute Result: "
        << maxSubArrayBrute(nums);

    cout
        << "\nBetter Result: "
        << maxSubArrayBetter(nums);

    cout
        << "\nOptimal Result: "
        << maxSubArrayOptimal(nums);

    return 0;
}