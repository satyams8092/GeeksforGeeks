class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxi=0;
        for(int &i:left){
            maxi=max(maxi, i);
        }
        
        for(int &i:right){
            maxi=max(maxi, n-i);
        }
        
        return maxi;
    }
};