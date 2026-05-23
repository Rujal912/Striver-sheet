// Question - Next Permutation
//
// Rearrange numbers into the next
// lexicographically greater permutation.
//
// If not possible,
// rearrange into lowest order.
//
// Must be done in-place.
//
// Example:
// [1,2,3]
// → [1,3,2]
//
// [3,2,1]
// → [1,2,3]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Optimal Approach
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Steps:
// 1. Find breakpoint
// 2. Find next greater element
// 3. Swap
// 4. Reverse remaining suffix
// -------------------------------------------------------------
void nextPermutationOptimal(
    vector<int>& nums
) {

    int n = nums.size();

    int ind = -1;

    // -------------------------------------------------
    // Step 1:
    // Find breakpoint
    //
    // Traverse from right.
    //
    // Find first index:
    //
    // nums[i] < nums[i+1]
    //
    // Example:
    // [2,1,5,4,3,0,0]
    //      ↑
    // breakpoint
    // -------------------------------------------------
    for (
        int i = n - 2;
        i >= 0;
        i--
    ) {

        if (
            nums[i]
            <
            nums[i + 1]
        ) {

            ind = i;

            break;
        }
    }

    // -------------------------------------------------
    // Step 2:
    // No breakpoint means
    // array already largest permutation
    //
    // Example:
    // [3,2,1]
    //
    // Answer:
    // [1,2,3]
    // -------------------------------------------------
    if (ind == -1) {

        reverse(
            nums.begin(),
            nums.end()
        );

        return;

        // IMPORTANT:
        // Otherwise nums[-1]
        // will cause invalid access
    }

    // -------------------------------------------------
    // Step 3:
    // Find next greater element
    // from right side
    // -------------------------------------------------
    for (
        int i = n - 1;
        i > ind;
        i--
    ) {

        if (
            nums[i]
            >
            nums[ind]
        ) {

            swap(
                nums[i],
                nums[ind]
            );

            break;
        }
    }

    // -------------------------------------------------
    // Step 4:
    // Reverse remaining suffix
    //
    // This produces
    // smallest possible next permutation
    // -------------------------------------------------
    reverse(
        nums.begin() + ind + 1,
        nums.end()
    );
}

// -------------------------------------------------------------
// STL Approach
//
// Time Complexity: O(n)
//
// Uses built-in algorithm
// -------------------------------------------------------------
void nextPermutationSTL(
    vector<int>& nums
) {

    next_permutation(
        nums.begin(),
        nums.end()
    );
}

void printArray(
    vector<int>& nums
) {

    for (int x : nums) {

        cout << x << " ";
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter size: ";

    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (
        int i = 0;
        i < n;
        i++
    ) {

        cin >> nums[i];
    }

    vector<int> optimal = nums;

    vector<int> stl = nums;

    nextPermutationOptimal(
        optimal
    );

    nextPermutationSTL(
        stl
    );

    cout << "\nOptimal Result:\n";

    printArray(
        optimal
    );

    cout << "\nSTL Result:\n";

    printArray(
        stl
    );

    return 0;
}