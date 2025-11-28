#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /* Function to get the second highest 
    occurring element in array */
    int secondMostFrequentElement(vector<int> &nums) {
        
        // Variable to store the size of array
        int n = nums.size();
        
        /* Variable to store maximum frequency
        and second Max frequency */
        int maxFreq = 0;
        int secMaxFreq = 0;
        
        /* Variable to store elements with most 
        and second most frequency */
        int maxEle = -1, secEle = -1;
        
        // Visited array
        vector<bool> visited(n, false);
        
        // First loop
        for(int i = 0; i < n; i++) {
            // Skip second loop if already visited
            if(visited[i]) continue;
            
            /* Variable to store frequency
            of current element */
            int freq = 0;
            
            // Second loop
            for(int j = i; j < n; j++) {
                if(nums[i] == nums[j]) {
                    freq++;
                    visited[j] = true;
                }
            }
            
            /* Update variables if new element  
            having highest frequency or second
            highest frequency is found */
            if(freq > maxFreq) {
                secMaxFreq = maxFreq;
                maxFreq = freq;
                secEle = maxEle;
                maxEle = nums[i];
            } 
            else if(freq == maxFreq) {
                maxEle = min(maxEle, nums[i]);
            }
            else if(freq > secMaxFreq) {
                secMaxFreq = freq;
                secEle = nums[i];
            }
            else if(freq == secMaxFreq) {
                secEle = min(secEle, nums[i]);
            }
            
        }
        
        // Return the result
        return secEle;
    }
};

int main() {
    vector<int> nums = {4, 4, 5, 5, 6, 7};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the second
    highest occurring element in array */
    int ans = sol.secondMostFrequentElement(nums);
    
    cout << "The second highest occurring element in the array is: " << ans;
    
    return 0;
}