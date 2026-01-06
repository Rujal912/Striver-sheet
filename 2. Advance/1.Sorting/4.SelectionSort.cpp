// Question - Selection Sort
// Selection Sort works by repeatedly selecting the minimum element
// from the unsorted part of the array and placing it at the beginning.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Selection Sort
vector<int> selectionSort(vector<int>& nums) {
    int n = nums.size();

    // We need to place elements from index 0 to n-2
    for (int i = 0; i <= n - 2; i++) {
        int mini = i;   // Assume current index has the minimum value

        // Find the index of the minimum element in the remaining array
        for (int j = i; j <= n - 1; j++) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }

        // Swap the found minimum element with the element at index i
        // Swapping an element with itself is harmless
        swap(nums[i], nums[mini]);

        // Optional optimization:
        // if (mini != i) {
        //     swap(nums[i], nums[mini]);
        // }
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

    vector<int> sortedArray = selectionSort(nums);

    cout << "Sorted array: ";
    for (int x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
