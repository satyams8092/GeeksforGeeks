//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                else if(mat[i][j]){
                    count++;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int siz = q.size();
            //if(siz) time++;
            while(siz--){
                pair<int,int>p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                if(i>0 && mat[i-1][j]==1){
                    mat[i-1][j]=2;
                    count--;
                   q.push({i-1,j});
                }
                if(i<n-1 && mat[i+1][j]==1){
                    mat[i+1][j]=2;
                    count--;
                    q.push({i+1,j});
                }
                if(j>0 && mat[i][j-1]==1){
                    mat[i][j-1]=2;
                    count--;
                    q.push({i,j-1});
                }
                if(j<m-1 && mat[i][j+1]==1){
                    mat[i][j+1]=2;
                    count--;
                    q.push({i,j+1});
                }
            }
            if(q.size()) time++;
        }
        if(count){
            return -1;
        }
        return time;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends