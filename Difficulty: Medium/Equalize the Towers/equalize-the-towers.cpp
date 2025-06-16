class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        long long n = heights.size(), maxi = 0, ans = 0, res = INT_MAX;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, 1LL * heights[i]);
            ans += (heights[i] - 1) * cost[i];
        }
        vector<long long> prefix(maxi + 1, 0);
        for(int i = 0; i < n; i++) prefix[heights[i]] += cost[i];
        for(int i = 1; i <= maxi; i++) prefix[i] += prefix[i - 1];
        res = ans;
        for(int i = 2; i <= maxi; i++) {
            ans += (2 * prefix[i - 1] - prefix[maxi]);
            res = min(res, ans);
        }
        return res;
    }
};
