#include<bits/stdc++.h>
using namespace std;


void createAdjList(vector < pair < int, int >> & edges, vector<vector<int>> &adj){
  for(int i =0; i< edges.size() ;i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }
}

bool dfsCycle(int node, vector<vector<int>> &adj , unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){

  visited[node] = true;
  dfsVisited[node] = true;
  for(auto neighbour : adj[node]){
    if( !visited[neighbour]){

      bool cycleDetected = dfsCycle(neighbour, adj , visited , dfsVisited);
      if(cycleDetected){
        return true;
      }
    }

    else if( dfsVisited[neighbour]){  // visited[neighbour] == true
      return true;
    }
  }
  // While returning from a call we have to make dfsVisited false for that node
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adj(n+1);
  createAdjList(edges, adj);

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for(int i=0 ; i< n ;i++){
    if(!visited[i]){
      bool cycleDetected = dfsCycle(i, adj , visited , dfsVisited);

      if(cycleDetected){
        return 1;
      }
    }
  }
  return 0;

}