#include<bits/stdc++.h>
using namespace std;

// DFS when adjency list is already given :

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<int> adj[], unordered_map<int , bool> &visited, vector<int> &ans ,int node){
        
        visited[node] = true;
        ans.push_back(node);
        
        for(auto i: adj[node]){
            if( !visited[i]){
                dfs(adj , visited , ans , i);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        dfs(adj, visited , ans, 0);
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// When adjency list is not given: 
/*
void prepareAdjList(vector<vector<int>> &edges,vector<vector<int>> &adj ){
    
    for(int i =0 ; i< edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}

void dfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component, int node){
    component.push_back(node);
    visited[node] = true;

    for(auto i: adj[node]){
        if( !visited[i]){
            dfs(adj, visited, component, i);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int ,bool> visited;
    vector<vector<int>> ans;
    vector<vector<int>> adj(V);

    prepareAdjList(edges , adj );

    for(int i=0 ; i< V ;i++){
        if( !visited[i]){
            vector<int> component;
            dfs(adj , visited , component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
*/