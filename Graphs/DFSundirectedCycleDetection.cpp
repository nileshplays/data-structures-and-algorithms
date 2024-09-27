//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool dfsCycle(int node ,int parent, vector<int> adj[], unordered_map<int, bool> &visited){
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            if( !visited[neighbour] ){
                bool cycleDetected = dfsCycle(neighbour, node , adj, visited);
                if(cycleDetected)
                    return true;
            }
            else if( neighbour != parent && visited[neighbour]){
                return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited;
        
        for(int i= 0; i< V; i++){
            if( !visited[i]){
                bool  ans = dfsCycle(i ,-1 , adj , visited);
                if(ans == 1)
                    return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends