// Question - Check for prime number
// A prime number is a number greater than 1 that has only two divisors: 1 and itself.

#include <iostream>
using namespace std;

// Function to check whether a number is prime
// Logic: Check divisibility from 2 to sqrt(n)
bool isPrime(int n) {
    if (n <= 1) return false;   // 1 and negative numbers are not prime

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;       // Found a divisor → not prime
        }
    }

    return true;                // No divisors found → prime number
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
        cout << "The number is a prime number." << endl;
    else
        cout << "The number is not a prime number." << endl;

    return 0;
}
