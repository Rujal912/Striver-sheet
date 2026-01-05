// Question - Factorial of a Given Number
// Factorial of n (n!) = n * (n-1) * (n-2) * ... * 1
// Special case: 0! = 1

#include <iostream>
using namespace std;

// Recursive function to calculate factorial
// Base Case: factorial(0) = 1
// Recursive Case: n * factorial(n - 1)
long long int factorial(int n) {
    if (n == 0) {
        return 1;                  // Base case
    }
    return n * factorial(n - 1);   // Recursive call
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    long long int result = factorial(n);

    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}
