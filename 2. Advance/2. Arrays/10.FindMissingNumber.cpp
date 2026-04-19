// Question - Find Missing Number
// Given an array of size n containing distinct numbers from 0 to n,
// exactly one number is missing. We need to find it.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Logic:
// Check for every number from 0 to n whether it exists in array
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

    return -1; // safety
}

// -------------------------------------------------------------
// Better Approach (Hashing)
// Time Complexity: O(n)
// Space Complexity: O(n)
// Logic:
// Use an array to mark presence of elements
// -------------------------------------------------------------
int missingNumberBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++) {
        hash[nums[i]] = 1;
    }

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
// Missing = expected - actual
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
// Optimal Approach 2 (XOR - Two Loop)
// Time Complexity: O(n)
// Space Complexity: O(1)
// -------------------------------------------------------------
int missingNumberOptimalXOR(vector<int>& nums) {
    int n = nums.size();

    int XOR1 = 0, XOR2 = 0;

    // XOR of 0 to n
    for (int i = 0; i <= n; i++) {
        XOR1 ^= i;
    }

    // XOR of array elements
    for (int i = 0; i < n; i++) {
        XOR2 ^= nums[i];
    }

    return XOR1 ^ XOR2;
}

// -------------------------------------------------------------
// Optimal Approach 2 (Best XOR - Single Loop)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// XOR numbers from 1..n and array elements simultaneously
// -------------------------------------------------------------
int missingNumberOptimalXORBest(vector<int>& nums) {
    int n = nums.size();

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor1 ^= (i + 1);   // 1 to n
        xor2 ^= nums[i];   // array values
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
    cout << "Optimal (Best XOR) Result: " << missingNumberOptimalXORBest(nums) << endl;

    return 0;
}