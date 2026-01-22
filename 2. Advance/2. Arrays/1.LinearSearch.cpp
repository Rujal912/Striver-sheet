// Question - Linear Search
// Linear Search checks each element one by one until
// the target element is found or the array ends.

#include <iostream>
#include <vector>
using namespace std;

// Function to perform Linear Search
// Returns the smallest index (0-based) where target is found
// If target is not present, returns -1
int linearSearch(vector<int>& nums, int target) {
    int n = nums.size();

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            return i;      // First occurrence found
        }
    }

    return -1;             // Target not found
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

    cout << "Enter target element: ";
    cin >> target;

    int index = linearSearch(nums, target);

    if (index == -1)
        cout << "Target not found in the array." << endl;
    else
        cout << "Target found at index: " << index << endl;

    return 0;
}
