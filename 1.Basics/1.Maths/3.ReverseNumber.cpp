// Question - Reverse a number
#include <iostream>
using namespace std;
// Function to reverse the digits of a number
// Logic: Extract last digit using %10, build reversed number by shifting left (×10)
int reverseNumber(int n) {
    int rev_num = 0;
    // Using n > 0 means it works only for positive numbers.
    // If you want to support negative numbers, use n != 0.
    while (n > 0) {
        int last_digit = n % 10;               // Extract last digit
        rev_num = (rev_num * 10) + last_digit; // Append digit to reversed number
        n = n / 10;                            // Remove last digit
    }
    return rev_num;                            // Return reversed number
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int reversed = reverseNumber(n);
    cout << "Reversed number = " << reversed << endl;
    return 0;
}