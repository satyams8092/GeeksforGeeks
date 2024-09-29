//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size()-1;
        int i=0,j=arr[i],jump=0,ma=1;
        if(arr[i]==0)return -1;
        if(arr[i]>=n)return 1;
        while(i<n){
            if(i+j+arr[i+j]>=n)return jump+2;
            if(i+j+arr[i+j]>=ma+arr[ma])ma=i+j;
            j--;
            if(j==0){
                if(arr[ma]==0)return -1;
                i=ma;
                jump++;
                ma=i+1;
                j=arr[i];
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends