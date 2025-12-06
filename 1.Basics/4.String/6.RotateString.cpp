// Question - Rotate String
// We check if string 's' can become 'goal' after some number of left-rotations.
// A rotation moves s[0] to the end of the string.

#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n²)
// Logic: Try all n possible rotations and compare with goal.
// -------------------------------------------------------------
bool rotateStringBrute(string& s, string& goal) {
    if (s.length() != goal.length()) {
        return false;       // lengths must match for rotation
    }

    int n = s.length();

    // Try all rotations
    for (int i = 0; i < n; i++) {
        string right = s.substr(i);     // take from index i to end
        string left = s.substr(0, i);   // take from start to i-1
        string rotated = right + left;  // rotated string

        if (rotated == goal) {
            return true;
        }
    }

    return false;
}

// -------------------------------------------------------------
// Optimal Approach
// Time Complexity: O(n)
// Logic: A rotated version of s must be a substring of s+s
// Example: "abcde" → "abcdeabcde"
// -------------------------------------------------------------
bool rotateStringOptimal(string& s, string& goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string doubled = s + s;

    // If goal exists inside doubled, it is a valid rotation
    return (doubled.find(goal) != string::npos);
}

int main() {
    string s, goal;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    bool bruteAns = rotateStringBrute(s, goal);
    bool optAns   = rotateStringOptimal(s, goal);

    cout << "\nBrute Force Result: ";
    cout << (bruteAns ? "true" : "false") << endl;

    cout << "Optimal Result: ";
    cout << (optAns ? "true" : "false") << endl;

    return 0;
}
