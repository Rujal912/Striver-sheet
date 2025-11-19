// Question - Count number of odd digits in a number
#include <iostream>
using namespace std;
// Function to count how many digits in the number are odd
// Logic: Extract each digit using %10, check if it's odd, then remove it using /10.
int countOddDigit(int n) {
    int count_odd = 0;
    while (n > 0) {
        int last_digit = n % 10;     // Extract last digit
        if (last_digit % 2 == 1) {   // Check if digit is odd
            count_odd++;
        }
        n = n / 10;                  // Remove last digit
    }
    return count_odd;               // Total odd digits
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = countOddDigit(n);
    cout << "Number of odd digits = " << result << endl;
    return 0;
}
