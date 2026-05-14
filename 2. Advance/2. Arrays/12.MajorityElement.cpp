// Question - Majority Element-I
// Majority element = element appearing more than n/2 times.
// The problem guarantees that a majority element exists.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Logic:
// For every element, count its frequency using another loop.
// -------------------------------------------------------------
int majorityElementBrute(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {

        int count = 0;

        // Count frequency of nums[i]
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        // Majority condition
        if (count > (n / 2)) {
            return nums[i];
        }
    }

    return -1;
}

// -------------------------------------------------------------
// Better Approach (Hashing using Map)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Logic:
// Store frequencies using a map.
// -------------------------------------------------------------
int majorityElementBetter(vector<int>& nums) {
    int n = nums.size();

    map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    // Find majority element
    for (auto it : freq) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}

// -------------------------------------------------------------
// Optimal Approach (Moore's Voting Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Logic:
// 1. Choose a candidate
// 2. Increase count if same element appears
// 3. Decrease count for different elements
// 4. Majority element survives in the end
// -------------------------------------------------------------
int majorityElementOptimal(vector<int>& nums) {
    int n = nums.size();

    int cnt = 0;
    int el = 0;

    // Finding potential majority element
    for (int i = 0; i < n; i++) {

        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        }
        else if (nums[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    // Verification step
    int cnt1 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == el) {
            cnt1++;
        }
    }

    if (cnt1 > (n / 2)) {
        return el;
    }

    return -1;
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

    cout << "\nBrute Result: "
         << majorityElementBrute(nums) << endl;

    cout << "Better Result: "
         << majorityElementBetter(nums) << endl;

    cout << "Optimal Result: "
         << majorityElementOptimal(nums) << endl;

    return 0;
}