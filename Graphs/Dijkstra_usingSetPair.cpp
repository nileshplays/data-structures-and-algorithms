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
        vector<int> distance(V,INT_MAX);
        set<pair<int,int> > st;
        distance[S] = 0;
        st.insert(make_pair(0,S));
        
        while( !st.empty()){
            
            // Fetch Top record in the set
            auto top = *st.begin();
            int nodeDist = top.first;
            int topNode = top.second;
            // Remove the top pair in the set
            st.erase(st.begin());
            
            // Traverse on neighbour
            for(auto neighbor : adj[topNode]){
                
                int nextNode = neighbor[0];
                int edgeWidth = neighbor[1];
                if(nodeDist + edgeWidth < distance[nextNode]){
                    
                    // Find  that node in set and delete earlier record
                    auto record = st.find(make_pair(distance[nextNode], nextNode));
                    // if Record found then erase that old record and add the minimum one :
                    if(record != st.end()){
                        st.erase(record);
                    }
                    // update distance
                    distance[nextNode] = nodeDist + edgeWidth;
                    // Push record
                    
                    st.insert(make_pair(distance[nextNode], nextNode));
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