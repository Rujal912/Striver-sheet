// Question - GCD of two numbers
// GCD (Greatest Common Divisor) is the largest number that divides both numbers.
// This uses the Euclidean Algorithm.

#include <iostream>
using namespace std;

// Function to compute GCD of two numbers using Euclid's Algorithm
int GCD(int n1, int n2) {
    // Continue until one number becomes zero
    while (n1 != 0 && n2 != 0) {
        if (n1 > n2) {
            n1 = n1 % n2;  // Reduce n1
        } else {
            n2 = n2 % n1;  // Reduce n2
        }
    }

    // One of them is zero. The other one is the GCD.
    if (n2 == 0) return n1;
    return n2;
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = GCD(a, b);

    cout << "GCD = " << result << endl;

    return 0;
}
