// Question - Longest Subarray With Sum K
//
// Return length of longest subarray
// having sum exactly equal to k.
//
// Example:
// [10,5,2,7,1,9]
// k=15
//
// Output:
// 4
//
// Subarray:
// [5,2,7,1]

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// -------------------------------------------------------------
// Brute Force
//
// Time Complexity: O(n²)
// Space Complexity: O(1)
//
// Generate all subarrays
// and calculate sum.
// -------------------------------------------------------------
int longestSubarrayBrute(
    vector<int>& nums,
    int k
) {

    int n = nums.size();

    int longest = 0;

    for (
        int i = 0;
        i < n;
        i++
    ) {

        long long sum = 0;

        for (
            int j = i;
            j < n;
            j++
        ) {

            sum += nums[j];

            if (
                sum == k
            ) {

                longest =
                    max(
                        longest,
                        j - i + 1
                    );
            }
        }
    }

    return longest;
}

// -------------------------------------------------------------
// Better Approach
// Prefix Sum + Hashing
//
// Works for:
// Positive
// Negative
// Zero
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// -------------------------------------------------------------
int longestSubarrayBetter(
    vector<int>& nums,
    int k
) {

    map<long long, int> prevSumMap;

    long long sum = 0;

    int longest = 0;

    for (
        int i = 0;
        i < nums.size();
        i++
    ) {

        sum += nums[i];

        // Entire array till i
        if (
            sum == k
        ) {

            longest =
                max(
                    longest,
                    i + 1
                );
        }

        long long rem =
            sum - k;

        if (
            prevSumMap.find(rem)
            !=
            prevSumMap.end()
        ) {

            int len =
                i -
                prevSumMap[rem];

            longest =
                max(
                    longest,
                    len
                );
        }

        // Store first occurrence only
        if (
            prevSumMap.find(sum)
            ==
            prevSumMap.end()
        ) {

            prevSumMap[sum] =
                i;
        }
    }

    return longest;
}

// -------------------------------------------------------------
// Optimal
// Sliding Window
//
// Works ONLY when array
// contains positives.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// -------------------------------------------------------------
int longestSubarrayOptimal(
    vector<int>& nums,
    int k
) {

    int n = nums.size();

    int left = 0;

    int right = 0;

    long long sum =
        nums[0];

    int longest = 0;

    while (
        right < n
    ) {

        while (
            left <= right
            &&
            sum > k
        ) {

            sum -= nums[left];

            left++;
        }

        if (
            sum == k
        ) {

            longest =
                max(
                    longest,
                    right - left + 1
                );
        }

        right++;

        if (
            right < n
        ) {

            sum += nums[right];
        }
    }

    return longest;
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

    int k;

    cout << "Enter k: ";

    cin >> k;

    vector<int> copy =
        nums;

    cout
        << "\nBrute: "
        << longestSubarrayBrute(
            nums,
            k
        );

    cout
        << "\nBetter: "
        << longestSubarrayBetter(
            nums,
            k
        );

    cout
        << "\nOptimal (positives only): "
        << longestSubarrayOptimal(
            copy,
            k
        );

    return 0;
}