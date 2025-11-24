// Question - Check for perfect number
// A perfect number is a number whose sum of proper divisors equals the number itself.
// Example: 6 = 1 + 2 + 3  → Perfect

#include <iostream>
using namespace std;

// Function to check whether a number is perfect
// Logic: Sum all divisors from 1 to sqrt(n), add both divisor pairs
bool isPerfect(int n) {
    // Perfect numbers must be > 1
    if (n <= 1) return false;

    int sum = 1;   // 1 is always a divisor

    // Check divisors until sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum = sum + i;           // Add divisor i
            if (i != (n / i)) {
                sum = sum + (n / i); // Add paired divisor
            }
        }
    }

    return (sum == n);  // Perfect if sum of divisors equals number
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPerfect(n))
        cout << "The number is a perfect number." << endl;
    else
        cout << "The number is not a perfect number." << endl;

    return 0;
}
