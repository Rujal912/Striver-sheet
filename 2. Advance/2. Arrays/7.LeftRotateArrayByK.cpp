// Question - Left Rotate Array by K Places
// Left rotation by k means shifting elements to the left by k positions.
// Example: nums = [1,2,3,4,5], k = 2 → [3,4,5,1,2]

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(k)
// Logic:
// 1. Store first k elements in a temporary array
// 2. Shift remaining elements to the left
// 3. Copy temp elements to the end
// -------------------------------------------------------------
void rotateArrayBrute(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k = k % n;  // Handle k >= n

    vector<int> temp;

    // Store first k elements
    for (int i = 0; i < k; i++) {
        temp.push_back(nums[i]);
    }

    // Shift remaining elements to the left
    for (int i = k; i < n; i++) {
        nums[i - k] = nums[i];
    }

    // Copy temp elements to the end
    for (int i = n - k; i < n; i++) {
        nums[i] = temp[i - (n - k)];
    }
}

// -------------------------------------------------------------
// Optimal Approach (Reversal Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic:
// 1. Reverse first k elements
// 2. Reverse remaining n-k elements
// 3. Reverse the whole array
// -------------------------------------------------------------
void reverseArray(vector<int>& nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotateArrayOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k = k % n;  // Handle k >= n

    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
    reverseArray(nums, 0, n - 1);
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    // Copies for both approaches
    vector<int> bruteArr = nums;
    vector<int> optArr   = nums;

    rotateArrayBrute(bruteArr, k);
    rotateArrayOptimal(optArr, k);

    cout << "\nBrute Result: ";
    for (int x : bruteArr) cout << x << " ";

    cout << "\nOptimal Result: ";
    for (int x : optArr) cout << x << " ";

    cout << endl;
    return 0;
}
