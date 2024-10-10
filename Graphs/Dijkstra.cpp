//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int> >> mini;
        mini.push(make_pair(0,S));
        
        while( !mini.empty()){
            
            // Fetching the nod wtih minimum distance
            pair<int,int> top = mini.top();
            
            mini.pop();
            int topNode= top.second;
            int nodeDist = top.first;
            
            //  Traversing neighbor of hte top node:;;
            for(auto neighbor : adj[topNode]){
                
                int nextNode = neighbor[0];
                int nextWeight = neighbor[1];
                
                // Checking if the distance is min or not
                if(nodeDist + nextWeight < distance[nextNode]){
                    distance[nextNode]  = nodeDist+ nextWeight;
                    
                    // push the updated distance for the node
                    mini.push(make_pair(distance[nextNode],nextNode));
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends