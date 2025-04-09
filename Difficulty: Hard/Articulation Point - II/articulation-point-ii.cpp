//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    private:
    int time = 0;
    
    void dfs(int node, int parent, vector<int> &tim, vector<int> &low, vector<int> &vis, vector<vector<int>> &adj, vector<int> &help) {
        vis[node] = 1;
        tim[node] = low[node] = time++;
        int child = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                child++;
                dfs(it, node, tim, low, vis, adj, help);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tim[node] && parent != -1) {
                    help[node] = 1;
                }
            } else {
                low[node] = min(low[node], tim[it]);
            }
        }
        if (parent == -1 && child > 1) {
            help[node] = 1;
        }
    }
  
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        // Convert edges list to adjacency list representation
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> tim(V, -1);
        vector<int> low(V, -1);
        vector<int> vis(V, 0);
        vector<int> help(V, -1);
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfs(i, -1, tim, low, vis, adj, help);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (help[i] == 1) {
                ans.push_back(i);
            }
        }
        
        if (ans.empty()) return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends