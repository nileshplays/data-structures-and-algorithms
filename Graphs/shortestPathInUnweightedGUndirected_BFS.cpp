#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

/*
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<bool> visited(n,0);
	unordered_map<int, list<int>> adj;

	for(int i=0 ;i< edges.size() ;i++){
		int u = edges[i].first; 
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	unordered_map<int, int> parent;

	//BFS
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neighbor: adj[front]){
			if( !visited[neighbor]){
				visited[neighbor] = true;
				parent[neighbor] = front;
				q.push(neighbor);
			}
		}
	}

	// Prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode!= s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);

	}

	reverse(ans.begin(), ans.end());
	return ans;
}

*/
