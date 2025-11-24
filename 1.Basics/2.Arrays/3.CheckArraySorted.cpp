// Question - Check if the Array is Sorted I
// We check if the array is sorted in non-decreasing order.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Logic: Compare every element with all elements ahead of it.
// -------------------------------------------------------------
bool arraySortedOrNot_Brute(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {   // If any next element is smaller → not sorted
                return false;
            }
        }
    }
    return true;
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Logic: Just check adjacent elements.
// If any arr[i] < arr[i-1], array is not sorted.
// -------------------------------------------------------------
bool arraySortedOrNot_Optimal(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {   // If current < previous → not sorted
            return false;
        }
    }
    return true;
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

    cout << endl;

    if (arraySortedOrNot_Brute(arr))
        cout << "Brute: Array is sorted." << endl;
    else
        cout << "Brute: Array is NOT sorted." << endl;

    if (arraySortedOrNot_Optimal(arr))
        cout << "Optimal: Array is sorted." << endl;
    else
        cout << "Optimal: Array is NOT sorted." << endl;

    return 0;
}
