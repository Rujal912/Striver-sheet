// Question - Palindrome number
// A number is palindrome if it reads the same forward and backward.

#include <iostream>
using namespace std;

// Function to check whether a number is palindrome
// Logic: Reverse the number and compare with original
bool isPalindrome(int n) {
    int number = n;        // Store original number
    int revNumber = 0;     // Will store reversed number

    while (n > 0) {
        int lastDigit = n % 10;              // Extract last digit
        revNumber = (revNumber * 10) + lastDigit; // Build reversed number
        n = n / 10;                          // Remove last digit
    }

    return (number == revNumber);            // Check if original == reversed
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool result = isPalindrome(n);

    if (result)
        cout << "The number is a palindrome." << endl;
    else
        cout << "The number is not a palindrome." << endl;

    return 0;
}
