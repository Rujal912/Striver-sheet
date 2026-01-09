// Question - Merge Sort
// Merge Sort is a Divide and Conquer algorithm.
// It divides the array into halves, sorts each half,
// and then merges the sorted halves.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Function to merge two sorted halves of the array
// Left half  : low -> mid
// Right half : mid+1 -> high
// -------------------------------------------------------------
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;     // Temporary array to store merged result

    int left = low;       // Pointer for left half
    int right = mid + 1;  // Pointer for right half

    // Compare elements from both halves and store smaller one
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // If elements remain in left half
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // If elements remain in right half
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// -------------------------------------------------------------
// Recursive Merge Sort function
// -------------------------------------------------------------
void ms(vector<int>& nums, int low, int high) {
    // Base case: single element is already sorted
    if (low == high) return;

    int mid = (low + high) / 2;

    // Sort left half
    ms(nums, low, mid);

    // Sort right half
    ms(nums, mid + 1, high);

    // Merge sorted halves
    merge(nums, low, mid, high);
}

// -------------------------------------------------------------
// Function to start Merge Sort
// -------------------------------------------------------------
vector<int> mergeSort(vector<int>& nums) {
    if (nums.size() == 0) return nums;
    ms(nums, 0, nums.size() - 1);
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

    vector<int> sortedArray = mergeSort(nums);

    cout << "Sorted array: ";
    for (int x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
