// Question - Left Rotate Array by One
// Left rotation by one means:
// [a, b, c, d] → [b, c, d, a]

#include <iostream>
#include <vector>
using namespace std;

// Function to rotate array to the left by one position
void rotateArrayByOne(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return;   // Edge case: empty array

    int temp = nums[0];  // Store first element

    // Shift all elements one position to the left
    for (int i = 1; i < n; i++) {
        nums[i - 1] = nums[i];
    }

    // Place the first element at the end
    nums[n - 1] = temp;
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

    rotateArrayByOne(nums);

    cout << "Array after left rotation by one: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
