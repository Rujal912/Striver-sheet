// Question - Highest occurring element in an array
// We find the element that appears the most times in the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Logic: For each element, count its frequency by scanning entire array.
// -------------------------------------------------------------
int mostFrequent_Brute(vector<int>& nums) {
    int visited[10001] = {0};     // To avoid recounting same number
    int maxCount = 0;
    int element = -1;

    for (int i = 0; i < nums.size(); i++) {
        int count = 0;

        if (visited[nums[i]] == 0) {
            visited[nums[i]] = 1;  // Mark as processed
        }

        // Count frequency of current element
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        // Update most frequent element
        if (count > maxCount) {
            maxCount = count;
            element = nums[i];
        }
        // If tie → choose smaller value
        else if (count == maxCount) {
            element = min(element, nums[i]);
        }
    }

    return element;
}

// -------------------------------------------------------------
// Optimal Approach (Hashing)
// Time Complexity: O(n)
// Logic: Count occurrences using a hash array, then find max frequency.
// -------------------------------------------------------------
int mostFrequent_Optimal(vector<int>& nums) {
    int maxi = nums[0];

    // Find maximum element to size hash array
    for (int i = 0; i < nums.size(); i++) {
        maxi = max(maxi, nums[i]);
    }

    vector<int> hash(maxi + 1, 0);   // Frequency array

    // Count frequency of each number
    for (int i = 0; i < nums.size(); i++) {
        hash[nums[i]]++;
    }

    int maxCount = 0, element = -1;

    // Find the number with highest frequency
    for (int i = 0; i <= maxi; i++) {
        if (hash[i] > maxCount) {
            maxCount = hash[i];
            element = i;
        }
    }

    return element;
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

    int bruteAns = mostFrequent_Brute(nums);
    int optAns   = mostFrequent_Optimal(nums);

    cout << "\nBrute Force Result: " << bruteAns << endl;
    cout << "Optimal Method Result: " << optAns << endl;

    return 0;
}
