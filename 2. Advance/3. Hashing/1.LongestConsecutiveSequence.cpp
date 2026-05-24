// Question - Longest Consecutive Sequence
//
// Given an unsorted array,
// return length of longest
// consecutive sequence.
//
// Example:
//
// [100,4,200,1,3,2]
//
// Sequence:
// [1,2,3,4]
//
// Answer:
// 4

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Logic:
// For every element,
// keep searching for next consecutive number.
// -------------------------------------------------------------

bool linearSearch(
    vector<int>& arr,
    int num
) {

    for (
        int i = 0;
        i < arr.size();
        i++
    ) {

        if (
            arr[i] == num
        ) {
            return true;
        }
    }

    return false;
}

int longestConsecutiveBrute(
    vector<int>& nums
) {

    int n = nums.size();

    if (n == 0) {
        return 0;
    }

    int longest = 1;

    for (
        int i = 0;
        i < n;
        i++
    ) {

        int x = nums[i];

        int cnt = 1;

        while (
            linearSearch(
                nums,
                x + 1
            )
        ) {

            x++;

            cnt++;
        }

        longest =
            max(
                longest,
                cnt
            );
    }

    return longest;
}

// -------------------------------------------------------------
// Better Approach
// Time Complexity: O(n log n)
// Space Complexity: O(1)
//
// Logic:
// Sort array.
//
// Count consecutive values.
//
// Ignore duplicates.
// -------------------------------------------------------------
int longestConsecutiveBetter(
    vector<int>& nums
) {

    int n = nums.size();

    if (n == 0) {
        return 0;
    }

    sort(
        nums.begin(),
        nums.end()
    );

    int lastSmaller =
        INT_MIN;

    int cnt = 0;

    int longest = 1;

    for (
        int i = 0;
        i < n;
        i++
    ) {

        if (
            nums[i] - 1
            ==
            lastSmaller
        ) {

            cnt++;

            lastSmaller =
                nums[i];
        }

        // Ignore duplicate
        else if (
            nums[i]
            !=
            lastSmaller
        ) {

            cnt = 1;

            lastSmaller =
                nums[i];
        }

        longest =
            max(
                longest,
                cnt
            );
    }

    return longest;
}

// -------------------------------------------------------------
// Optimal Approach
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Logic:
//
// Store elements in hashset.
//
// Start sequence only if:
//
// current-1 does not exist
//
// This guarantees sequence
// starts only once.
// -------------------------------------------------------------
int longestConsecutiveOptimal(
    vector<int>& nums
) {

    int n = nums.size();

    if (n == 0) {

        return 0;
    }

    unordered_set<int> st;

    for (
        int x : nums
    ) {

        st.insert(x);
    }

    int longest = 1;

    for (
        auto it : st
    ) {

        // Start only from sequence start
        if (
            st.find(it - 1)
            ==
            st.end()
        ) {

            int x = it;

            int cnt = 1;

            while (
                st.find(
                    x + 1
                )
                !=
                st.end()
            ) {

                x++;

                cnt++;
            }

            longest =
                max(
                    longest,
                    cnt
                );
        }
    }

    return longest;
}

int main() {

    int n;

    cout
        << "Enter size: ";

    cin >> n;

    vector<int> nums(n);

    cout
        << "Enter elements: ";

    for (
        int i = 0;
        i < n;
        i++
    ) {

        cin >> nums[i];
    }

    vector<int> copy =
        nums;

    cout
        << "\nBrute Result: "
        << longestConsecutiveBrute(nums);

    cout
        << "\nBetter Result: "
        << longestConsecutiveBetter(copy);

    cout
        << "\nOptimal Result: "
        << longestConsecutiveOptimal(nums);

    return 0;
}