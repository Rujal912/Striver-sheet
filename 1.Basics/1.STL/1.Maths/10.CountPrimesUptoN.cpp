// Question - Count number of prime numbers up to N
// Example: For N = 10 → primes are 2, 3, 5, 7 → count = 4

#include <iostream>
using namespace std;

// Helper function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;    // 1 and negative numbers are not prime

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;        // Found a divisor → not prime
        }
    }

    return true;                 // No divisors found → prime number
}

// Function to count total prime numbers from 1 to n
int primeUptoN(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {        // Check if i is prime
            count++;             // Increase count
        }
    }

    return count;                // Return total prime numbers
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = primeUptoN(n);

    cout << "Total prime numbers up to " << n << " = " << result << endl;

    return 0;
}
