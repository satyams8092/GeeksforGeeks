//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
         int vote=0;
        int element=-1;
        for(int i=0;i<arr.size();i++){
            if(vote==0){
                vote=1;
                element=arr[i];
            }
            else if(arr[i]==element){
                vote++;
            }
            else{
                vote--;
            }
          
        }
        vote=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element){
                vote++;
            }
        }
        
        return vote>arr.size()/2?element:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends