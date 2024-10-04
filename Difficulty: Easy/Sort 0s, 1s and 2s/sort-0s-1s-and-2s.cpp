//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        vector<int>arr1;
        vector<int>arr2;
        vector<int>arr3;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr1.push_back(arr[i]);
            }
            else if(arr[i]==1){
                arr2.push_back(arr[i]);
                
            }
            else{
                arr3.push_back(arr[i]);
                
            }
        }
        vector<int>arr4;
        arr4.insert(arr4.end(), arr1.begin(), arr1.end());
        arr4.insert(arr4.end(), arr2.begin(), arr2.end());  
        arr4.insert(arr4.end(), arr3.begin(), arr3.end());
        arr=arr4;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends