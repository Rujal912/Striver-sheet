// Question - Maximum Consecutive Ones
// Given a binary array (only 0s and 1s),
// we need to find the maximum number of consecutive 1s.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find maximum consecutive ones
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();

    int count = 0;      // Counts current consecutive 1s
    int maxCount = 0;   // Stores maximum consecutive 1s found so far

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;                        // Increase current streak
            maxCount = max(maxCount, count); // Update maximum
        } else {
            count = 0;                      // Reset streak when 0 is found
        }
    }

    return maxCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter binary array elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones = " << result << endl;

    return 0;
}
