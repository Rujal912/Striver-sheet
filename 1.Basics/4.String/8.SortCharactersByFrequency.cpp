// Question - Sort Characters by Frequency
// We are given a string and need to return unique characters
// sorted by:
// 1) Highest frequency first
// 2) If frequencies are same, alphabetically smaller character first

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Comparator function for sorting
// - Higher frequency comes first
// - If frequency is same, lexicographically smaller character comes first
static bool comparator(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;
}

// Function to sort characters by frequency
vector<char> frequencySort(string& s) {
    // Array of pairs: {frequency, character}
    pair<int, char> freq[26];

    // Initialize frequency array
    for (int i = 0; i < 26; i++) {
        freq[i] = {0, char('a' + i)};
    }

    // Count frequency of each character
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a'].first++;
    }

    // Sort using custom comparator
    sort(freq, freq + 26, comparator);

    vector<char> ans;

    // Store only characters with non-zero frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i].first == 0) break;
        ans.push_back(freq[i].second);
    }

    return ans;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<char> result = frequencySort(s);

    cout << "Characters sorted by frequency: ";
    for (char c : result) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
