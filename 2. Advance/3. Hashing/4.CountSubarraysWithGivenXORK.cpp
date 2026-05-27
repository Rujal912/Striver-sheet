// ======================================================
// Count Subarrays With Given XOR K
//
// Return total number of subarrays
// whose XOR is exactly equal to K.
// ======================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// ------------------------------------------------------
// Brute Force
//
// TC → O(n³)
// SC → O(1)
//
// Generate all subarrays
// Calculate XOR separately
// ------------------------------------------------------

int subarraysWithXorKBrute(
    vector<int>& nums,
    int k
) {

    int n = nums.size();

    int count = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i; j < n; j++) {

            int XOR = 0;

            for(int x = i; x <= j; x++) {

                XOR = XOR ^ nums[x];
            }

            if(XOR == k) {
                count++;
            }
        }
    }

    return count;
}



// ------------------------------------------------------
// Better
//
// TC → O(n²)
// SC → O(1)
//
// Keep extending XOR
// instead of recalculating
// ------------------------------------------------------

int subarraysWithXorKBetter(
    vector<int>& nums,
    int k
) {

    int n = nums.size();

    int count = 0;

    for(int i = 0; i < n; i++) {

        int XOR = 0;

        for(int j = i; j < n; j++) {

            XOR = XOR ^ nums[j];

            if(XOR == k) {
                count++;
            }
        }
    }

    return count;
}



// ------------------------------------------------------
// Optimal → Prefix XOR + Hashing
//
// TC → O(n)
// SC → O(n)
//
// Formula:
//
// prefixXOR ^ oldXOR = k
//
// oldXOR = prefixXOR ^ k
// ------------------------------------------------------

int subarraysWithXorKOptimal(
    vector<int>& nums,
    int k
) {

    int xr = 0;

    int count = 0;

    map<int, int> prefixMap;

    // XOR 0 occurred once
    prefixMap[0] = 1;

    for(int i = 0; i < nums.size(); i++) {

        // Current prefix XOR
        xr = xr ^ nums[i];

        // Required previous XOR
        int x = xr ^ k;

        // Count all matches
        count += prefixMap[x];

        // Store frequency
        prefixMap[xr]++;
    }

    return count;
}



int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    cout << "Enter XOR value: ";
    cin >> k;

    vector<int> copy = nums;

    cout
        << "\nBrute Result: "
        << subarraysWithXorKBrute(nums, k);

    cout
        << "\nBetter Result: "
        << subarraysWithXorKBetter(nums, k);

    cout
        << "\nOptimal Result: "
        << subarraysWithXorKOptimal(nums, k);

    return 0;
}