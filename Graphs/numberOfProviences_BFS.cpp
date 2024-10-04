#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>> &isConnected, vector<bool> &visited){
        // int m = isConnected[0].size();
        visited[node] = true;

        for(int i =0; i< isConnected.size() ; i++ ){

            if(!visited[i] && isConnected[node][i]){
                dfs(i , isConnected , visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n,false);
        int count =0 ;
        for(int i =0; i<n ;i++){

            if( !visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        } 

        return count;       
    }
};