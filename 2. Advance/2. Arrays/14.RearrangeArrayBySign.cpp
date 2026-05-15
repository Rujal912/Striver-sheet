// Question - Rearrange Array Elements by Sign
//
// Given an array containing equal number of positive
// and negative numbers:
//
// Conditions:
// 1. Alternate positive and negative numbers
// 2. Preserve relative order
// 3. Start with a positive number

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Logic:
// 1. Store positive numbers separately
// 2. Store negative numbers separately
// 3. Place positives at even indexes
// 4. Place negatives at odd indexes
// -------------------------------------------------------------
vector<int> rearrangeArrayBrute(vector<int>& nums) {

    int n = nums.size();

    vector<int> pos;
    vector<int> neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {

        if (nums[i] > 0) {
            pos.push_back(nums[i]);
        }
        else {
            neg.push_back(nums[i]);
        }
    }

    // Fill array alternatively
    for (int i = 0; i < n / 2; i++) {

        nums[2 * i] = pos[i];       // Even index → positive
        nums[2 * i + 1] = neg[i];   // Odd index → negative
    }

    return nums;
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Logic:
// Directly place positives and negatives
// at their correct indexes while traversing once.
//
// Positive indexes → 0,2,4...
// Negative indexes → 1,3,5...
// -------------------------------------------------------------
vector<int> rearrangeArrayOptimal(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++) {

        // Place negative number at odd index
        if (nums[i] < 0) {

            ans[negIndex] = nums[i];
            negIndex += 2;
        }

        // Place positive number at even index
        else {

            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter size of array (even): ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> bruteAns = rearrangeArrayBrute(nums);
    vector<int> optimalAns = rearrangeArrayOptimal(nums);

    cout << "\nBrute Result: ";

    for (int x : bruteAns) {
        cout << x << " ";
    }

    cout << "\nOptimal Result: ";

    for (int x : optimalAns) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}