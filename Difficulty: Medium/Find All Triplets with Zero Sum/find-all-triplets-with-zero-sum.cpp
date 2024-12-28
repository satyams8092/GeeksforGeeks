//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int target= -arr[i];
            unordered_map<int,vector<int>>mp;
                for(int j=0;j<n&&j!=i;j++){
                    if(mp[target-arr[j]].size()>0){
                        int size =mp[target-arr[j]].size();
                      
                        for(int k =0;k<size;k++){
                            int bada=max({j,mp[target-arr[j]][k],i});
                        int chota=min({j,mp[target-arr[j]][k],i});
                        int middle=(j+mp[target-arr[j]][k]+i)-(bada+chota);
                        ans.push_back({chota,middle,bada});
                          
                        }
                      
                    }
                    mp[arr[j]].push_back(j);
                }
           
        }
        return ans;
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends