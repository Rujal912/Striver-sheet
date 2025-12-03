// Question - Reverse a string
// We reverse the characters inside a vector<char>.

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n) because we use a temporary array
void reverseStringBrute(vector<char>& s) {
    int n = s.size();
    vector<char> dup(n);

    // Store characters in reverse order
    for (int i = 0; i < n; i++) {
        dup[n - i - 1] = s[i];
    }

    // Copy back to original vector
    for (int i = 0; i < n; i++) {
        s[i] = dup[i];
    }
}

// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseStringOptimal(vector<char>& s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);  // Swap characters
        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size of string: ";
    cin >> n;

    vector<char> s(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Make copies for brute + optimal
    vector<char> bruteS = s;
    vector<char> optS = s;

    reverseStringBrute(bruteS);
    reverseStringOptimal(optS);

    cout << "\nBrute Reversed String: ";
    for (char c : bruteS) cout << c;
    cout << endl;

    cout << "Optimal Reversed String: ";
    for (char c : optS) cout << c;
    cout << endl;

    return 0;
}
