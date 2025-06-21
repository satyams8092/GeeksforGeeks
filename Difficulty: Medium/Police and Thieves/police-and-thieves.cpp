class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>t,p;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='T') t.push_back(i);
            else p.push_back(i);
        }
        
        int i=0,j=0;
        int ans=0;
        while(i<t.size() && j<p.size()){
            if(abs(t[i]-p[j])<=k){
                ans++;
                i++;
                j++;
            }
            else if(t[i]<p[j]){
                i++;
            }
            else j++;
        }
        return ans;
    }
};