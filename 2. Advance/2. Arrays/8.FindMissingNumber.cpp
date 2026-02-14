// Question - Find Missing Number
// Given an array of size n containing distinct numbers in range [0, n],
// exactly one number is missing. We need to find it.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Logic:
// For every number from 0 to n, check if it exists in the array.
// -------------------------------------------------------------
int missingNumberBrute(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i <= n; i++) {
        bool found = false;

        for (int j = 0; j < n; j++) {
            if (nums[j] == i) {
                found = true;
                break;
            }
        }

        if (!found) return i;
    }
    return -1; // safety (won’t reach)
}

// -------------------------------------------------------------
// Better Approach (Hashing)
// Time Complexity: O(n)
// Space Complexity: O(n)
// Logic:
// Mark presence of elements using a hash array.
// -------------------------------------------------------------
int missingNumberBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++) {
        hash[nums[i]] = 1;
    }

    // Numbers range from 0 to n (inclusive)
    for (int i = 0; i <= n; i++) {
        if (hash[i] == 0) return i;
    }

    return -1;
}

// -------------------------------------------------------------
// Optimal Approach 1 (Sum Formula)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// Expected sum = n*(n+1)/2
// Missing number = expected sum - actual sum
// -------------------------------------------------------------
int missingNumberOptimalSum(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

// -------------------------------------------------------------
// Optimal Approach 2 (XOR)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// XOR of numbers from 1..n with XOR of array elements
// Remaining value is the missing number.
// -------------------------------------------------------------
int missingNumberOptimalXOR(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    // xor1 → XOR of 1 to n
    // xor2 → XOR of array elements
    for (int i = 0; i < n; i++) {
        xor1 ^= (i + 1);   // includes n
        xor2 ^= nums[i];
    }

    return xor1 ^ xor2;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements (0 to n with one missing): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "\nBrute Result: " << missingNumberBrute(nums) << endl;
    cout << "Better Result: " << missingNumberBetter(nums) << endl;
    cout << "Optimal (Sum) Result: " << missingNumberOptimalSum(nums) << endl;
    cout << "Optimal (XOR) Result: " << missingNumberOptimalXOR(nums) << endl;

    return 0;
}
