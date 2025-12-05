// Question - Isomorphic String
// Two strings are isomorphic if characters in 's' can be replaced to form 't'
// Conditions:
// 1. One-to-one mapping between characters.
// 2. No two characters in 's' can map to the same character in 't'.
// 3. Order must be preserved.

#include <iostream>
#include <string>
using namespace std;

// Function to check if two strings are isomorphic
bool isomorphicString(string s, string t) {
    if (s.length() != t.length()) return false;

    int sMap[256] = {0};   // Mapping from s[i] to t[i]
    int tMap[256] = {0};   // Mapping from t[i] to s[i]

    for (int i = 0; i < s.size(); i++) {

        // If either character is already mapped,
        // verify that mapping remains consistent.
        if ( (sMap[s[i]] != 0 || tMap[t[i]] != 0) &&
            (sMap[s[i]] != t[i] + 1 || tMap[t[i]] != s[i] + 1) ) {
            return false;
        }

        // Create mapping (+1 ensures we differentiate from default zero)
        sMap[s[i]] = t[i] + 1;
        tMap[t[i]] = s[i] + 1;
    }

    return true;   // Passed all checks
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    bool result = isomorphicString(s, t);

    if (result)
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are NOT isomorphic." << endl;

    return 0;
}
