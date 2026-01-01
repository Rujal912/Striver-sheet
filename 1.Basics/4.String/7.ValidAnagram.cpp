// Question - Valid Anagram
// Two strings are anagrams if they contain the same characters
// with the same frequencies, possibly in a different order.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n log n)
// Logic:
// 1. If lengths differ → not anagrams
// 2. Sort both strings
// 3. If sorted strings are equal → anagrams
// -------------------------------------------------------------
bool anagramStringsBrute(string s, string t) {
    if (s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s == t);
}

// -------------------------------------------------------------
// Optimal Approach (Updated)
// Time Complexity: O(n)
// Space Complexity: O(1) (fixed size arrays of 26)
// Logic:
// 1. Count frequency of each character in both strings
// 2. Compare frequency arrays
// -------------------------------------------------------------
bool anagramStringsOptimal(string s, string t) {
    if (s.size() != t.size()) return false;

    int freqS[26] = {0};
    int freqT[26] = {0};

    // Count frequencies for both strings
    for (int i = 0; i < s.size(); i++) {
        freqS[s[i] - 'a']++;
        freqT[t[i] - 'a']++;
    }

    // Compare frequency arrays
    for (int i = 0; i < 26; i++) {
        if (freqS[i] != freqT[i]) {
            return false;
        }
    }

    return true;  // All character counts match
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
