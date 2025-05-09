//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> diff(n);
        
        // Step 1: Transform the array
        for (int i = 0; i < n; ++i) {
            diff[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> prefixIndex; // Stores first occurrence of each prefix sum
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; ++i) {
            prefixSum += diff[i];

            // Case 1: Entire subarray from 0 to i has sum > 0
            if (prefixSum > 0) {
                maxLen = i + 1;
            }
            // Case 2: Check if prefixSum - 1 was seen before
            else if (prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[prefixSum - 1]);
            }

            // Store the first occurrence of this prefix sum
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends