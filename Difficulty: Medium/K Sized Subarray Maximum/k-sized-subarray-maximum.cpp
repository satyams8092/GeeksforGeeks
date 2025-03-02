//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> max_arr;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
           // Remove elements out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
               dq.pop_front();
            }

           // Remove elements smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                 dq.pop_back();
            }

           // Add the current element to the deque
            dq.push_back(i);

            // Start adding results to max_arr after we have processed the first 'k' elements
            if (i >= k - 1) {
               max_arr.push_back(arr[dq.front()]);
            }
        }

        return max_arr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends