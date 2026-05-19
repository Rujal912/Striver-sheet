// Question - Two Sum
//
// Given an array and a target,
// return indices of two numbers such that:
//
// nums[i] + nums[j] = target
//
// Same element cannot be used twice.
//
// Return answer in any order.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Logic:
// Check every possible pair.
// -------------------------------------------------------------
vector<int> twoSumBrute(vector<int>& nums, int target) {

    int n = nums.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            // Pair found
            if (nums[i] + nums[j] == target) {

                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// -------------------------------------------------------------
// Better Approach (Hashing using Map)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
//
// Logic:
// For every number:
// needed = target - current number
//
// If needed already exists in map,
// answer found.
// -------------------------------------------------------------
vector<int> twoSumBetter(vector<int>& nums, int target) {

    map<int, int> mpp;

    int n = nums.size();

    for (int i = 0; i < n; i++) {

        int num = nums[i];

        // Number needed to reach target
        int moreNeeded = target - num;

        // If complement exists
        if (mpp.find(moreNeeded) != mpp.end()) {

            return {mpp[moreNeeded], i};
        }

        // Store current number with index
        mpp[num] = i;
    }

    return {-1, -1};
}

// -------------------------------------------------------------
// Optimal Approach (Sorting + Two Pointer)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
//
// Logic:
// 1. Store values with original indices
// 2. Sort array
// 3. Use two pointers
//
// Important:
// We store original indices because sorting changes positions.
// -------------------------------------------------------------
vector<int> twoSumOptimal(vector<int>& nums, int target) {

    int n = nums.size();

    // Store {value, original_index}
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {

        arr.push_back({nums[i], i});
    }

    // Sort according to values
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int sum = arr[left].first + arr[right].first;

        // Pair found
        if (sum == target) {

            return {arr[left].second, arr[right].second};
        }

        // Need bigger sum
        else if (sum < target) {

            left++;
        }

        // Need smaller sum
        else {

            right--;
        }
    }

    return {-1, -1};
}

int main() {

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {

        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> bruteAns = twoSumBrute(nums, target);
    vector<int> betterAns = twoSumBetter(nums, target);
    vector<int> optimalAns = twoSumOptimal(nums, target);

    cout << "\nBrute Result: "
         << bruteAns[0] << " " << bruteAns[1] << endl;

    cout << "Better Result: "
         << betterAns[0] << " " << betterAns[1] << endl;

    cout << "Optimal Result: "
         << optimalAns[0] << " " << optimalAns[1] << endl;

    return 0;
}