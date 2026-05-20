// Question - 3 Sum
//
// Find all unique triplets such that:
// nums[i] + nums[j] + nums[k] = 0
//
// Conditions:
// i != j, i != k, j != k
//
// Triplets must be unique.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^3 * log(no. of unique triplets))
// Space Complexity: O(no. of unique triplets)
//
// Logic:
// Try every possible triplet using 3 loops.
// Use set to avoid duplicate triplets.
// -------------------------------------------------------------
vector<vector<int>> threeSumBrute(vector<int>& nums) {

    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                if (nums[i] + nums[j] + nums[k] == 0) {

                    vector<int> temp = {nums[i], nums[j], nums[k]};

                    // Sort triplet to handle duplicates
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }
            }
        }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// -------------------------------------------------------------
// Better Approach (Hashing)
// Time Complexity: O(n^2 * log(unique triplets))
// Space Complexity: O(n)
//
// Logic:
// Fix first element.
// Use hashing to find third element.
// -------------------------------------------------------------
vector<vector<int>> threeSumBetter(vector<int>& nums) {

    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        set<int> hashset;

        for (int j = i + 1; j < n; j++) {

            int third = -(nums[i] + nums[j]);

            // Third element found
            if (hashset.find(third) != hashset.end()) {

                vector<int> temp = {nums[i], nums[j], third};

                sort(temp.begin(), temp.end());

                st.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// -------------------------------------------------------------
// Optimal Approach (Sorting + Two Pointer)
// Time Complexity: O(n^2)
// Space Complexity: O(1) excluding output
//
// Logic:
// 1. Sort array
// 2. Fix one element
// 3. Use two pointers for remaining part
//
// Important:
// Skip duplicates to avoid repeated triplets.
// -------------------------------------------------------------
vector<vector<int>> threeSumOptimal(vector<int>& nums) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // Skip duplicate elements for i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k) {

            int sum = nums[i] + nums[j] + nums[k];

            // Need smaller sum
            if (sum > 0) {
                k--;
            }

            // Need bigger sum
            else if (sum < 0) {
                j++;
            }

            // Triplet found
            else {

                vector<int> temp = {nums[i], nums[j], nums[k]};

                ans.push_back(temp);

                j++;
                k--;

                // Skip duplicate values for j
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                // Skip duplicate values for k
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }

    return ans;
}

// Function to print 2D vector
void printAnswer(vector<vector<int>>& ans) {

    cout << "[ ";

    for (auto vec : ans) {

        cout << "[";

        for (int i = 0; i < vec.size(); i++) {

            cout << vec[i];

            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }

        cout << "] ";
    }

    cout << "]";
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

    vector<vector<int>> bruteAns = threeSumBrute(nums);
    vector<vector<int>> betterAns = threeSumBetter(nums);
    vector<vector<int>> optimalAns = threeSumOptimal(nums);

    cout << "\nBrute Result: ";
    printAnswer(bruteAns);

    cout << "\n\nBetter Result: ";
    printAnswer(betterAns);

    cout << "\n\nOptimal Result: ";
    printAnswer(optimalAns);

    cout << endl;

    return 0;
}