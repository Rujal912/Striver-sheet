// Question - Count all digits of a number
#include <iostream>
using namespace std;
// Function to count number of digits in integer n
// Logic: Repeatedly divide by 10 to remove last digit.
// Each division counts as one digit.
int countDigit(int n) {
    // Special case: if number is 0, it has exactly 1 digit
    if (n == 0) {
        return 1;
    }
    int count = 0;
    // Loop until all digits are removed
    while (n > 0) {
        n = n / 10;   // Removes last digit
        count++;      // Count each digit removed
    }
    return count;     // Return total digits counted
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int digits = countDigit(n);
    cout << "Total digits = " << digits << endl;
    return 0;
}