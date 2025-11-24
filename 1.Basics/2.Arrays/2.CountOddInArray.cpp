// Question - Count of odd numbers in an array

#include <iostream>
#include <vector>
using namespace std;

// Function to count total odd numbers in the array
int countOdd(vector<int>& arr) {
    int oddCount = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {    // Check if element is odd
            oddCount++;
        }
    }

    return oddCount;             // Return total odd numbers
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);         // Dynamic array

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countOdd(arr);

    cout << "Count of odd numbers = " << result << endl;

    return 0;
}
