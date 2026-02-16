// Question - Union of Two Sorted Arrays
// Given two sorted arrays, return a sorted array containing
// all distinct elements present in either of the arrays.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// -------------------------------------------------------------
// Brute / Simple Approach (Using Set)
// Time Complexity: O((n1 + n2) log(n1 + n2))
// Space Complexity: O(n1 + n2)
// Logic:
// 1. Insert all elements of both arrays into a set
// 2. Set automatically removes duplicates and keeps elements sorted
// -------------------------------------------------------------
vector<int> unionArrayBrute(vector<int>& nums1, vector<int>& nums2) {
    set<int> st;

    // Insert elements of first array
    for (int i = 0; i < nums1.size(); i++) {
        st.insert(nums1[i]);
    }

    // Insert elements of second array
    for (int i = 0; i < nums2.size(); i++) {
        st.insert(nums2[i]);
    }

    // Copy set elements to vector
    vector<int> Union;
    for (auto it : st) {
        Union.push_back(it);
    }

    return Union;
}

// -------------------------------------------------------------
// Optimal Approach (Two Pointer Technique)
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2)
// Logic:
// 1. Use two pointers to traverse both sorted arrays
// 2. Add smaller element and skip duplicates
// -------------------------------------------------------------
vector<int> unionArrayOptimal(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    vector<int> Union;

    while (i < n1 && j < n2) {
        if (nums1[i] <= nums2[j]) {
            if (Union.empty() || Union.back() != nums1[i]) {
                Union.push_back(nums1[i]);
            }
            i++;
        } else {
            if (Union.empty() || Union.back() != nums2[j]) {
                Union.push_back(nums2[j]);
            }
            j++;
        }
    }

    // Remaining elements of nums1
    while (i < n1) {
        if (Union.empty() || Union.back() != nums1[i]) {
            Union.push_back(nums1[i]);
        }
        i++;
    }

    // Remaining elements of nums2
    while (j < n2) {
        if (Union.empty() || Union.back() != nums2[j]) {
            Union.push_back(nums2[j]);
        }
        j++;
    }

    return Union;
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

    vector<int> bruteAns = unionArrayBrute(nums1, nums2);
    vector<int> optAns   = unionArrayOptimal(nums1, nums2);

    cout << "\nBrute Result: ";
    for (int x : bruteAns) cout << x << " ";

    cout << "\nOptimal Result: ";
    for (int x : optAns) cout << x << " ";

    cout << endl;
    return 0;
}
