// Question - LCM of two numbers
// LCM (Least Common Multiple) is the smallest number divisible by both numbers.
// Formula: LCM(a, b) = (a * b) / GCD(a, b)

#include <iostream>
using namespace std;

// Helper function to compute GCD using Euclid's Algorithm
int GCD(int n1, int n2) {
    while (n1 != 0 && n2 != 0) {
        if (n1 > n2) {
            n1 = n1 % n2;   // Reduce n1
        } else {
            n2 = n2 % n1;   // Reduce n2
        }
    }

    if (n1 == 0) return n2;
    return n1;
}

// Function to compute LCM using the GCD formula
int LCM(int n1, int n2) {
    return (n1 * n2) / GCD(n1, n2);
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = LCM(a, b);

    cout << "LCM = " << result << endl;

    return 0;
}
