// Question - Intersection of Two Sorted Arrays
// Return common elements present in both arrays.
// If an element appears x times in nums1 and y times in nums2,
// include it min(x, y) times in result.

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n1 * n2)
// Space Complexity: O(n2)
// Logic:
// 1. For each element in nums1, check in nums2
// 2. Use visited array to avoid reusing same element
// 3. Since arrays are sorted, break early if nums2[j] > nums1[i]
// -------------------------------------------------------------
vector<int> intersectionBrute(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> vis(n2, 0);  // Track used elements
    vector<int> ans;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {

            // Match found and not used before
            if (nums1[i] == nums2[j] && vis[j] == 0) {
                ans.push_back(nums1[i]);
                vis[j] = 1;
                break;
            }

            // Since sorted, no need to check further
            if (nums2[j] > nums1[i]) break;
        }
    }

    return ans;
}

// -------------------------------------------------------------
// Optimal Approach (Two Pointer)
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1) (excluding output)
// Logic:
// 1. Use two pointers i and j
// 2. Move the smaller pointer forward
// 3. If equal, add to result and move both
// -------------------------------------------------------------
vector<int> intersectionOptimal(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    vector<int> bruteAns = intersectionBrute(nums1, nums2);
    vector<int> optAns   = intersectionOptimal(nums1, nums2);

    cout << "\nBrute Result: ";
    for (int x : bruteAns) cout << x << " ";

    cout << "\nOptimal Result: ";
    for (int x : optAns) cout << x << " ";

    cout << endl;

    return 0;
}