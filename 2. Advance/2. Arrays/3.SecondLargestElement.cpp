// Question - Second Largest Element in an Array
// We need to return the second largest DISTINCT element.
// If it does not exist, return -1.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n log n)
// Logic:
// 1. Sort the array
// 2. Traverse from end and find first element != largest
// -------------------------------------------------------------
int secondLargestBrute(vector<int> nums) {
    int n = nums.size();

    if (n < 2) return -1;

    sort(nums.begin(), nums.end());

    int largest = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] != largest) {
            return nums[i];
        }
    }

    return -1; // No second largest element
}

// -------------------------------------------------------------
// Better Approach (Two Pass)
// Time Complexity: O(n)
// Logic:
// 1. Find largest element
// 2. Find largest element smaller than the largest
// -------------------------------------------------------------
int secondLargestBetter(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1;

    int largest = nums[0];
    int secondLargest = INT_MIN;
    bool found = false;

    // First pass: find largest
    for (int i = 0; i < n; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    // Second pass: find second largest
    for (int i = 0; i < n; i++) {
        if (nums[i] < largest && nums[i] > secondLargest) {
            secondLargest = nums[i];
            found = true;
        }
    }

    return found ? secondLargest : -1;
}

// -------------------------------------------------------------
// Optimal Approach (Single Pass)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// Track largest and second largest together
// -------------------------------------------------------------
int secondLargestOptimal(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1;

    int largest = nums[0];
    int sLargest = INT_MIN;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (nums[i] > largest) {
            sLargest = largest;
            largest = nums[i];
            found = true;
        }
        // Handles cases like [8,8,7,6,5]
        else if (nums[i] < largest && nums[i] > sLargest) {
            sLargest = nums[i];
            found = true;
        }
    }

    return found ? sLargest : -1;
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

    cout << "\nBrute Force Result: " << secondLargestBrute(nums) << endl;
    cout << "Better Approach Result: " << secondLargestBetter(nums) << endl;
    cout << "Optimal Approach Result: " << secondLargestOptimal(nums) << endl;

    return 0;
}
