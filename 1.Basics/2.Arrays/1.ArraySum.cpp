// Question - Sum of all elements in an array

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate sum of all elements in an array
int sum(vector<int>& arr) {
    int total = 0;

    for (int i = 0; i < arr.size(); i++) {
        total += arr[i];
    }

    return total;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);    // Dynamic array

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sum(arr);

    cout << "Sum of array elements = " << result << endl;

    return 0;
}
