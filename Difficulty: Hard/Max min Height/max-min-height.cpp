class Solution {
  public:
      bool check(int mid , vector<int> &arr , int k , int w)
    {
        int n = arr.size();
        vector<int>Pref(n + 1 , 0);
        for(int i = 1; i <= n; i++)
        {
            int x = arr[i - 1];
            Pref[i] += Pref[i - 1];
            int h = x + Pref[i];
            if(h < mid)
            {
                int diff = mid - h;
                if(diff > k)
                    return false;
                Pref[i] += diff;
                if(i + w <= n)
                    Pref[i + w] -= diff;
                    k -= diff;
            }
        }
        return true;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) 
    {
        int start = *min_element(arr.begin() , arr.end());
        int end = start + k;
        int ans = start;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(check(mid , arr , k , w))
                ans = mid , start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
};