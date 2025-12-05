// Question - Longest Common Prefix
// We find the longest starting substring that appears in all strings.
// Logic:
// 1. Sort the array of strings.
// 2. Only compare the first and last strings (they will differ the most).
// 3. The common prefix between them is the answer.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to find longest common prefix among array of strings
string longestCommonPrefix(vector<string>& str) {
    if (str.empty()) return "";

    // Sorting brings similar prefixes closer
    sort(str.begin(), str.end());

    string first = str[0];
    string last = str[str.size() - 1];
    int minLength = min(first.size(), last.size());

    string ans = "";

    // Compare characters of first and last string
    for (int i = 0; i < minLength; i++) {
        if (first[i] != last[i]) {
            break;                  // Stop at mismatch
        }
        ans += first[i];
    }

    return ans;   // Returns "" if no common prefix exists
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> str(n);
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    string result = longestCommonPrefix(str);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
