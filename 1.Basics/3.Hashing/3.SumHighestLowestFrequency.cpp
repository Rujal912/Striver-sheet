// Question - Sum of Highest and Lowest Frequency
// We find the highest occurring element's frequency,
// and the lowest occurring element's frequency,
// then return their sum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Logic: For each unique element, count its frequency,
//        then track max and min frequencies.
// -------------------------------------------------------------
int sumHighestAndLowestFrequency_Brute(vector<int>& nums) {
    int n = nums.size();
    int vis[10001] = {0};

    int maxfreq = 0;
    int minfreq = n;

    for (int i = 0; i < n; i++) {

        if (vis[nums[i]] == 1) continue;
        vis[nums[i]] = 1;

        int count = 0;

        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        maxfreq = max(maxfreq, count);
        minfreq = min(minfreq, count);
    }

    return maxfreq + minfreq;
}

// -------------------------------------------------------------
// Optimal Approach (Hashing)
// Time Complexity: O(n)
// Logic: Use a frequency array to count and then
//        find maximum and minimum non-zero frequencies.
// -------------------------------------------------------------
int sumHighestAndLowestFrequency_Optimal(vector<int>& nums) {
    int maxi = nums[0];

    // Find maximum value so we can size hash array
    for (int x : nums) {
        maxi = max(maxi, x);
    }

    vector<int> hash(maxi + 1, 0);

    // Count frequencies
    for (int x : nums) {
        hash[x]++;
    }

    int maxfreq = 0;
    int minfreq = nums.size();

    // Find highest & lowest non-zero frequencies
    for (int i = 0; i <= maxi; i++) {
        if (hash[i] != 0) {
            maxfreq = max(maxfreq, hash[i]);
            minfreq = min(minfreq, hash[i]);
        }
    }

    return maxfreq + minfreq;
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

    int bruteAns = sumHighestAndLowestFrequency_Brute(nums);
    int optAns   = sumHighestAndLowestFrequency_Optimal(nums);

    cout << "\nBrute Force Result: " << bruteAns << endl;
    cout << "Optimal Result: " << optAns << endl;

    return 0;
}
