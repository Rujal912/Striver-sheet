// Question - 4 Sum
//
// Find all unique quadruplets such that:
//
// nums[a] + nums[b] + nums[c] + nums[d] = target
//
// Conditions:
// a,b,c,d must be distinct
// No duplicate quadruplets.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^4 * log(unique))
// Space Complexity: O(unique quadruplets)
//
// Logic:
// Try every possible quadruplet.
// Sort quadruplet before inserting into set
// to remove duplicates.
// -------------------------------------------------------------
vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {

    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                for (int l = k + 1; l < n; l++) {

                    long long sum = nums[i];

                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k],
                            nums[l]
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------------------
// Better Approach (Hashing)
// Time Complexity: O(n^3 * log(unique))
// Space Complexity: O(n)
//
// Logic:
// Fix first two elements.
// Use hashset to find fourth element.
// -------------------------------------------------------------
vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {

    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            set<long long> hashset;

            for (int k = j + 1; k < n; k++) {

                long long sum =
                    nums[i] +
                    nums[j] +
                    nums[k];

                long long fourth =
                    target - sum;

                if (hashset.find(fourth) != hashset.end()) {

                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        nums[k],
                        (int)fourth
                    };

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashset.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------------------------------------------------
// Optimal Approach (Sorting + Two Pointer)
// Time Complexity: O(n^3)
// Space Complexity: O(1) excluding output
//
// Logic:
// 1. Sort array
// 2. Fix first two numbers
// 3. Solve remaining using two pointers
//
// Important:
// Skip duplicates
// Use long long to avoid overflow
// -------------------------------------------------------------
vector<vector<int>> fourSumOptimal(
    vector<int>& nums,
    int target
) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // Skip duplicate i
        if (i > 0 &&
            nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {

            // Skip duplicate j
            if (j != i + 1 &&
                nums[j] == nums[j - 1]) {
                continue;
            }

            int k = j + 1;
            int l = n - 1;

            while (k < l) {

                long long sum =
                    nums[i];

                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target) {

                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k],
                        nums[l]
                    });

                    k++;
                    l--;

                    // Skip duplicate k
                    while (
                        k < l &&
                        nums[k] ==
                        nums[k - 1]
                    ) {
                        k++;
                    }

                    // Skip duplicate l
                    while (
                        k < l &&
                        nums[l] ==
                        nums[l + 1]
                    ) {
                        l--;
                    }
                }

                else if (sum < target) {

                    k++;
                }

                else {

                    l--;
                }
            }
        }
    }

    return ans;
}

// Print 2D vector
void printAnswer(
    vector<vector<int>>& arr
) {

    cout << "[ ";

    for (auto row : arr) {

        cout << "[";

        for (
            int i = 0;
            i < row.size();
            i++
        ) {

            cout << row[i];

            if (
                i !=
                row.size() - 1
            ) {
                cout << ", ";
            }
        }

        cout << "] ";
    }

    cout << "]";
}

int main() {

    int n, target;

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

    cout << "Enter target: ";
    cin >> target;

    auto brute =
        fourSumBrute(
            nums,
            target
        );

    auto better =
        fourSumBetter(
            nums,
            target
        );

    auto optimal =
        fourSumOptimal(
            nums,
            target
        );

    cout << "\nBrute Result:\n";
    printAnswer(brute);

    cout << "\n\nBetter Result:\n";
    printAnswer(better);

    cout << "\n\nOptimal Result:\n";
    printAnswer(optimal);

    return 0;
}