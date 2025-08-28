// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size(),d;
        
        int d1= arr[1]-arr[0];
        int d2= arr[n-1]-arr[n-2];
        if(d1>0) {
            if(d1==d2) d=d1;
            else d=min(d1,d2);
        }
        else{
            if(d1==d2) d=d1;
            else d=max(d1,d2);
        }
        
        if(arr[0]==arr[1]) return arr[0];
        
        if(d>0){
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                int nth=arr[0] + (mid+1-1)*d;
                if(nth < arr[mid]) r=mid-1;
                else l=mid+1;
            }
            if(l>=n-1){
                 if(arr[n-1]-d == arr[n-2]) return arr[n-1]+d;
                 else return arr[n-1]-d;
            }
            else return arr[l]-d;
        }
            else{
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                int nth=arr[0] + (mid+1-1)*d;
                if(nth > arr[mid]) r=mid-1;
                else l=mid+1;
            }
            if(l>=n-1){
                 if(arr[n-1]-d == arr[n-2]) return arr[n-1] + d;
             else return arr[n-1] - d;
            }
            else return arr[l] - d;
        }
    }
};