// Question - Check if a string is palindrome
// A string is palindrome if it reads the same from left and right.

#include <iostream>
#include <string>
using namespace std;

// Function to check palindrome
// Logic: Use two pointers (left, right) and compare character pairs
bool palindromeCheck(string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {   // If mismatch → not palindrome
            return false;
        }
        left++;
        right--;
    }
    return true;                    // All characters matched
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    bool result = palindromeCheck(s);

    if (result)
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
