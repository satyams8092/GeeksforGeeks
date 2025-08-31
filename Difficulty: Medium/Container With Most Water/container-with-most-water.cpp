class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        int maxi=0;
        while(i<j){
            int len=j-i;
            int mini=min(arr[i],arr[j]);
            maxi=max(maxi,len*mini);
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        return maxi;
    }
};