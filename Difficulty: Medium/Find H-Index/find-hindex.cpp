//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int>suffix(n);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(citations[i] >= n) cnt++;
            else
            suffix[citations[i]]++;
        }
    
        suffix[n-1]+=cnt;
        for(int i=n-2;i>=0;i--){
            suffix[i]+=suffix[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(suffix[i] < i) return i-1;
        }
        
        if(n <= cnt) return n;
        return n-1;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends