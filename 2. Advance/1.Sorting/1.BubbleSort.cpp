// Question - Bubble Sort
// Bubble Sort repeatedly swaps adjacent elements if they are in the wrong order.
// After each pass, the largest element moves (bubbles) to the end of the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bubble Sort
vector<int> bubbleSort(vector<int>& nums) {
    int n = nums.size();

    // Outer loop runs from last index to index 1
    for (int i = n - 1; i >= 1; i--) {

        int didSwap = 0;   // Flag to check if any swap happened in this pass

        // Inner loop compares adjacent elements
        for (int j = 0; j <= i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                didSwap = 1;   // A swap occurred
            }
        }

        // If no swap happened, array is already sorted
        if (didSwap == 0) {
            break;
        }
    }

    return nums;
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

    vector<int> sortedArray = bubbleSort(nums);

    cout << "Sorted array: ";
    for (int x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
