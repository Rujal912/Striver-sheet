// Question - Check if the number is Armstrong
// An Armstrong number equals the sum of its own digits raised to the power of total digits.
// Example: 153 = 1³ + 5³ + 3³

#include <iostream>
#include <cmath>
using namespace std;
// Helper function to count digits in a number
// Using log10(n) + 1 to get total digits efficiently
int countDigit(int n) {
    int count = log10(n) + 1;
    return count;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int n) {
    int count = countDigit(n);  // Number of digits
    int sum = 0;
    int copy = n;               // Store original number
    while (n > 0) {
        int lastDigit = n % 10;           // Extract last digit
        sum = sum + pow(lastDigit, count); // Add digit^count to sum
        n = n / 10;                       // Remove last digit
    }
    return (copy == sum);  // Armstrong check
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    bool result = isArmstrong(n);

    if (result)
        cout << "The number is an Armstrong number." << endl;
    else
        cout << "The number is not an Armstrong number." << endl;

    return 0;
}
