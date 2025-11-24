// Question - Factorial of a given number
// Factorial(n) = 1 * 2 * 3 * ... * n

#include <iostream>
using namespace std;

// Function to compute factorial of a number
// Logic: Multiply all numbers from 1 to n
int factorial(int n) {
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        ans = ans * i;  // Multiply current number
    }

    return ans;         // Return final factorial
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = factorial(n);

    cout << "Factorial = " << result << endl;

    return 0;
}

