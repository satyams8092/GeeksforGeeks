class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        int n = intervals.size();
        if(n < k) return -1;
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        
        for(int i=n-1;i>=0;i--){
            pq.push(intervals[i][0]);
            while(!pq.empty() && pq.top() > intervals[i][1]){
                pq.pop();
            }
            if(pq.size() == k){
                return intervals[i][1];
            }
        }
        
        return -1;
    }
};