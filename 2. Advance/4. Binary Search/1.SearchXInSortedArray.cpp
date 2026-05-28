// ======================================================
// Search X in Sorted Array
//
// Return index of target element
// If target is not present return -1
//
// Binary Search works only on sorted arrays
// ======================================================

#include <iostream>
#include <vector>

using namespace std;


// ------------------------------------------------------
// Iterative Binary Search
//
// TC → O(log n)
// SC → O(1)
//
// Repeatedly divide search space into half
// ------------------------------------------------------

int searchIterative(
    vector<int>& nums,
    int target
) {

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while(low <= high) {

        // Safer way to calculate mid
        // avoids overflow
        int mid =
            low + (high - low) / 2;

        if(nums[mid] == target) {

            return mid;
        }

        // Search in right half
        else if(nums[mid] < target) {

            low = mid + 1;
        }

        // Search in left half
        else {

            high = mid - 1;
        }
    }

    return -1;
}




// ------------------------------------------------------
// Recursive Binary Search
//
// TC → O(log n)
// SC → O(log n)
//
// Extra space due to recursion stack
// ------------------------------------------------------

int BS(
    vector<int>& nums,
    int low,
    int high,
    int target
) {

    // Base case
    if(low > high) {
        return -1;
    }

    int mid =
        low + (high - low) / 2;

    if(nums[mid] == target) {

        return mid;
    }

    else if(nums[mid] > target) {

        return BS(
            nums,
            low,
            mid - 1,
            target
        );
    }

    return BS(
        nums,
        mid + 1,
        high,
        target
    );
}


int searchRecursive(
    vector<int>& nums,
    int target
) {

    return BS(
        nums,
        0,
        nums.size() - 1,
        target
    );
}




int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    cout
        << "\nIterative Result: "
        << searchIterative(nums, target);

    cout
        << "\nRecursive Result: "
        << searchRecursive(nums, target);

    return 0;
}