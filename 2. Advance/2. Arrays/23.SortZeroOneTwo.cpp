// Question - Sort an Array of 0's, 1's and 2's
//
// Sort array in-place.
// Array contains only:
// 0, 1, 2
//
// Example:
// [1,0,2,1,0]
// Output:
// [0,0,1,1,2]

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Better Approach (Counting)
// Time Complexity: O(2n)
// Space Complexity: O(1)
//
// Logic:
// Count occurrences of:
// 0, 1, 2
//
// Then overwrite array.
// -------------------------------------------------------------
void sortZeroOneTwoBetter(vector<int>& nums) {

    int n = nums.size();

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    // Count frequency
    for (int i = 0; i < n; i++) {

        if (nums[i] == 0) {
            cnt0++;
        }

        else if (nums[i] == 1) {
            cnt1++;
        }

        else {
            cnt2++;
        }
    }

    // Fill zeros
    for (int i = 0; i < cnt0; i++) {
        nums[i] = 0;
    }

    // Fill ones
    for (
        int i = cnt0;
        i < cnt0 + cnt1;
        i++
    ) {
        nums[i] = 1;
    }

    // Fill twos
    for (
        int i = cnt0 + cnt1;
        i < n;
        i++
    ) {
        nums[i] = 2;
    }
}

// -------------------------------------------------------------
// Optimal Approach
// Dutch National Flag Algorithm
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Pointers:
//
// low → ending position of 0
// mid → current element
// high → starting position of 2
//
// Regions:
//
// 0 → low-1      → sorted 0s
// low → mid-1    → sorted 1s
// mid → high     → unsorted
// high+1 → n-1   → sorted 2s
// -------------------------------------------------------------
void sortZeroOneTwoOptimal(
    vector<int>& nums
) {

    int n = nums.size();

    int low = 0;

    int mid = 0;

    int high = n - 1;

    while (mid <= high) {

        // Put 0 in left region
        if (nums[mid] == 0) {

            swap(
                nums[low],
                nums[mid]
            );

            low++;
            mid++;
        }

        // 1 already in correct region
        else if (
            nums[mid] == 1
        ) {

            mid++;
        }

        // Put 2 in right region
        else {

            swap(
                nums[mid],
                nums[high]
            );

            high--;

            // Don't move mid
            // because swapped value
            // still needs checking
        }
    }
}

// Print function
void printArray(
    vector<int>& nums
) {

    for (int x : nums) {

        cout << x << " ";
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter size: ";

    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (
        int i = 0;
        i < n;
        i++
    ) {

        cin >> nums[i];
    }

    vector<int> better = nums;

    vector<int> optimal = nums;

    sortZeroOneTwoBetter(
        better
    );

    sortZeroOneTwoOptimal(
        optimal
    );

    cout << "\nBetter Result: ";

    printArray(
        better
    );

    cout << "\nOptimal Result: ";

    printArray(
        optimal
    );

    return 0;
}