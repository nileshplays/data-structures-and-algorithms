//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool bfsCycle(int node , vector<int> adj[], unordered_map<int, bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;
        
        q.push(node);
        visited[node] = true;
        parent[node] = -1;
        
        while( !q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto neighbour: adj[frontNode]){
                if( visited[neighbour] && neighbour !=parent[frontNode]){
                    return true;
                }
                
                else if( !visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
        
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited;
        
        for(int i =0 ; i < V ;i++){
            if( !visited[i]){
                bool ans = bfsCycle(i , adj , visited);
                
                if(ans == 1)
                    return 1;
            }
            
        }
        return 0;
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