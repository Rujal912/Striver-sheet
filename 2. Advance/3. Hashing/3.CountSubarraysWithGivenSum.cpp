// ======================================================
// Count Subarrays With Given Sum
//
// Return total number of subarrays
// whose sum is exactly equal to K.
// ======================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// ------------------------------------------------------
// Brute Force
//
// TC → O(n³)
// SC → O(1)
//
// Generate all subarrays
// Calculate sum for every subarray
// ------------------------------------------------------

int subarraySumBrute(vector<int>& nums, int k) {

    int n = nums.size();

    int count = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i; j < n; j++) {

            int sum = 0;

            // Calculate current subarray sum
            for(int x = i; x <= j; x++) {
                sum += nums[x];
            }

            if(sum == k) {
                count++;
            }
        }
    }

    return count;
}



// ------------------------------------------------------
// Better
//
// TC → O(n²)
// SC → O(1)
//
// Keep extending current subarray
// instead of recalculating sum
// ------------------------------------------------------

int subarraySumBetter(vector<int>& nums, int k) {

    int n = nums.size();

    int count = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += nums[j];

            if(sum == k) {
                count++;
            }
        }
    }

    return count;
}



// ------------------------------------------------------
// Optimal → Prefix Sum + Hashing
//
// TC → O(n)
// SC → O(n)
//
// Works for:
// Positive
// Negative
// Zero
//
// Idea:
//
// currentPrefix - oldPrefix = k
//
// oldPrefix = currentPrefix - k
// ------------------------------------------------------

int subarraySumOptimal(vector<int>& nums, int k) {

    map<int, int> prefixMap;

    // Important:
    // Prefix sum 0 appeared once
    // Helps count subarrays starting from index 0
    prefixMap[0] = 1;

    int prefixSum = 0;

    int count = 0;

    for(int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        // Required prefix
        int remove = prefixSum - k;

        // Add all occurrences
        count += prefixMap[remove];

        // Increase frequency
        prefixMap[prefixSum]++;
    }

    return count;
}



int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    cout << "Enter target sum: ";
    cin >> k;

    vector<int> copy = nums;

    cout << "\nBrute Result: "
         << subarraySumBrute(nums, k);

    cout << "\nBetter Result: "
         << subarraySumBetter(nums, k);

    cout << "\nOptimal Result: "
         << subarraySumOptimal(nums, k);

    return 0;
}