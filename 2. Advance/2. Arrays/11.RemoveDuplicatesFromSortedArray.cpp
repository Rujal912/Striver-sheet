// Question - Remove Duplicates from Sorted Array
// Given a sorted array, remove duplicates in-place such that
// each unique element appears only once.
//
// Return the count of unique elements.
//
// Example:
// Input  : [1,1,2,2,3]
// Output : [1,2,3] and k = 3

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach (Using Set)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Logic:
// 1. Insert all elements into a set
// 2. Set automatically removes duplicates
// 3. Copy unique elements back into original array
// -------------------------------------------------------------
int removeDuplicatesBrute(vector<int>& nums) {
    int n = nums.size();

    set<int> st;

    // Insert all elements into set
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    int index = 0;

    // Copy unique elements back to array
    for (auto it : st) {
        nums[index] = it;
        index++;
    }

    return index; // Number of unique elements
}

// -------------------------------------------------------------
// Optimal Approach (Two Pointer)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// i → points to last unique element
// j → traverses array
//
// When nums[j] is different from nums[i],
// place nums[j] at next unique position.
// -------------------------------------------------------------
int removeDuplicatesOptimal(vector<int>& nums) {
    int n = nums.size();

    // If array is empty
    if (n == 0) return 0;

    int i = 0;

    for (int j = 1; j < n; j++) {

        // New unique element found
        if (nums[i] != nums[j]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }

    // Total unique elements
    return (i + 1);
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create copies for both approaches
    vector<int> bruteArr = nums;
    vector<int> optArr   = nums;

    int k1 = removeDuplicatesBrute(bruteArr);
    int k2 = removeDuplicatesOptimal(optArr);

    cout << "\nBrute Result: ";
    for (int i = 0; i < k1; i++) {
        cout << bruteArr[i] << " ";
    }

    cout << "\nNumber of unique elements: " << k1 << endl;

    cout << "\nOptimal Result: ";
    for (int i = 0; i < k2; i++) {
        cout << optArr[i] << " ";
    }

    cout << "\nNumber of unique elements: " << k2 << endl;

    return 0;
} 