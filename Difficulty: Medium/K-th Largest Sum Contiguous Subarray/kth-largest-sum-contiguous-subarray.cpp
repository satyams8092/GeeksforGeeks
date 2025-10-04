// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        return v[v.size()-k];
    }
};