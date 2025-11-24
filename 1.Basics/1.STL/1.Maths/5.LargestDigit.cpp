// Question - Return the largest digit in a number
#include <iostream>
using namespace std;
// Function to find the largest digit in a number
// Logic: Extract each digit and compare it with current largest
int largestDigit(int n) {
    int largest = 0;   // Stores the maximum digit found
    while (n > 0) {
        int last_digit = n % 10;   // Extract last digit
        if (last_digit > largest) {
            largest = last_digit;  // Update largest digit
        }
        n = n / 10;                // Remove last digit
    }
    return largest;                // Return largest digit found
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = largestDigit(n);
    cout << "Largest digit = " << result << endl;
    return 0;
}
