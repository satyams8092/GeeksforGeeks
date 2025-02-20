//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     void balance(priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini){
        if(maxi.size() > mini.size()+1){
            mini.push(maxi.top());
            maxi.pop();
        }
        else if(mini.size() > maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
        return;
    }
    
    
    void putEle(int x,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini){
        if(maxi.size()==0 || maxi.top()>x){
            maxi.push(x);
        }
        else
            mini.push(x);
        
        balance(maxi,mini);
        return;
    }
    
    
    
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        priority_queue<int> maxi;
        priority_queue<int,vector<int>,greater<int>> mini;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            putEle(arr[i],maxi,mini);
            if(maxi.size() == mini.size()){
                double t = (maxi.top() + mini.top())/2.0;
                ans.push_back(t);
            }
            else
                ans.push_back(maxi.top());
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends