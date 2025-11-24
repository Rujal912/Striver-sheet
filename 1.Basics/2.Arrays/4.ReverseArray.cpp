// Question - Reverse an array
// We reverse the entire array so that arr[0] becomes last and arr[n-1] becomes first.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n) because we use an extra array
// Logic: Create a temporary array and fill it from end to start.
// -------------------------------------------------------------
void reverseBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[n - i - 1] = arr[i];   // Reverse mapping
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];           // Copy back
    }
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic: Swap left & right elements and move pointers.
// -------------------------------------------------------------
void reverseOptimal(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Copy original array for brute and optimal separately
    vector<int> bruteArr = arr;
    vector<int> optArr   = arr;

    // Apply brute force
    reverseBrute(bruteArr);

    // Apply optimal method
    reverseOptimal(optArr);

    cout << "\nBrute Reversed Array: ";
    for (int x : bruteArr) cout << x << " ";

    cout << "\nOptimal Reversed Array: ";
    for (int x : optArr) cout << x << " ";

    cout << endl;

    return 0;
}
