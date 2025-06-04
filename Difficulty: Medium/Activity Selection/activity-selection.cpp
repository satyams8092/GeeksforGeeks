class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int, int>>arr; 
        for(int i=0; i<start.size(); i++){
            arr.push_back({start[i], finish[i]}); 
        }
        
        sort(arr.begin(), arr.end()); 
        
        int ans=1, j=0;
        
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1].first>arr[j].second){
                ++ans; 
                j=i+1;
            }
            else if(arr[i+1].second<arr[j].second){
                j=i+1;
            }
        }
        
        return ans; 
    }
};