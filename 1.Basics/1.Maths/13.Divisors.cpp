// Question - Divisors of a Number
// Divisors are numbers that divide 'n' without leaving a remainder.

#include <iostream>
#include <vector>
using namespace std;

// Function to return all divisors of a number
// Logic: Check every number from 1 to n and store those that divide n
vector<int> divisors(int n) {
    vector<int> vec;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {       // If i divides n completely
            vec.push_back(i);   // Store it in vector
        }
    }

    return vec;                // Return the list of divisors
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = divisors(n);

    cout << "Divisors: ";
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
