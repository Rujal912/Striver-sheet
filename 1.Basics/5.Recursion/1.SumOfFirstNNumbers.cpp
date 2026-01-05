// Question - Sum of First N Numbers
// We calculate the sum of first N natural numbers using recursion.
// Natural numbers: 1, 2, 3, ..., N

#include <iostream>
using namespace std;

// Recursive function to find sum of first N natural numbers
// Base Case: If N == 0, sum is 0
// Recursive Case: N + sum of first (N-1) numbers
int NnumbersSum(int N) {
    if (N == 0) {
        return 0;                 // Base case
    }
    return N + NnumbersSum(N - 1); // Recursive call
}

int main() {
    int N;

    cout << "Enter N: ";
    cin >> N;

    int result = NnumbersSum(N);

    cout << "Sum of first " << N << " natural numbers = " << result << endl;

    return 0;
}
