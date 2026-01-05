// Question - Sum of Array Elements
// We calculate the sum of all elements in an array using recursion.

#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function
// i represents the current index
// Base Case: when index reaches array size, return 0
// Recursive Case: current element + sum of remaining elements
int solve(vector<int>& nums, int i) {
    if (i == nums.size()) {
        return 0;                 // Base case
    }
    return nums[i] + solve(nums, i + 1);
}

// Function to start recursion
int arraySum(vector<int>& nums) {
    return solve(nums, 0);
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

    int result = arraySum(nums);

    cout << "Sum of array elements = " << result << endl;

    return 0;
}
