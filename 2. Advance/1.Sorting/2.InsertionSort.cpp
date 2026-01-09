// Question - Insertion Sort
// Insertion Sort builds the sorted array one element at a time.
// It works the way we sort playing cards in hand.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Insertion Sort
vector<int> insertionSort(vector<int>& nums) {
    int n = nums.size();

    // We start from index 0 to n-1
    for (int i = 0; i <= n - 1; i++) {
        int j = i;

        // Move the current element left until it is in correct position
        while (j > 0 && nums[j - 1] > nums[j]) {
            swap(nums[j - 1], nums[j]);
            j--;
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

    vector<int> sortedArray = insertionSort(nums);

    cout << "Sorted array: ";
    for (int x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
