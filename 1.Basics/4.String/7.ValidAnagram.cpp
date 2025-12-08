// Question - Valid Anagram
// Two strings are anagrams if they contain the same characters
// in any order, with identical frequencies.

// We solve this using:
// 1. Brute (sorting both strings)
// 2. Optimal (using frequency counting)

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n log n)
// Logic: Sort both strings and compare
// -------------------------------------------------------------
bool anagramStringsBrute(string s, string t) {
    // If lengths differ → not anagrams
    if (s.length() != t.length()) return false;

    // Sort characters so identical strings become equal
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s == t);
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Logic: Count frequency of each character (ASCII 256 chars)
// -------------------------------------------------------------
bool anagramStringsOptimal(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> freq(256, 0);

    // Count in s, subtract in t
    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;   // character in s
        freq[t[i]]--;   // character in t
    }

    // If all zeros → frequencies matched
    for (int x : freq) {
        if (x != 0) return false;
    }

    return true;
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    bool bruteAns = anagramStringsBrute(s, t);
    bool optAns   = anagramStringsOptimal(s, t);

    cout << "\nBrute Result: " << (bruteAns ? "true" : "false") << endl;
    cout << "Optimal Result: " << (optAns ? "true" : "false") << endl;

    return 0;
}
