// Question - Largest Odd Number in a String
// We want the largest prefix of the string which forms an odd number.
// Steps:
// 1. Find the rightmost odd digit.
// 2. Remove leading zeros.
// 3. Return substring from first non-zero up to that odd digit.

#include <iostream>
#include <string>
using namespace std;

// Function to return largest odd number present as a substring
string largeOddNum(string& s) {
    int n = s.length();
    int j = -1;

    // Find last position of an odd digit (digit % 2 == 1)
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 1) {
            j = i;
            break;
        }
    }

    // If no odd digit found → no odd-number possible
    if (j == -1) return "";

    // Skip leading zeros
    int i = 0;
    while (i < n && s[i] == '0') {
        i++;
    }

    // Return substring from first non-zero digit to last odd digit
    return s.substr(i, j - i + 1);
}

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    string result = largeOddNum(s);

    if (result == "")
        cout << "No odd number can be formed." << endl;
    else
        cout << "Largest odd number: " << result << endl;

    return 0;
}
