//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isSafe(int nextX , int nextY,int n,vector<vector<int>> &mat,
        vector<vector<bool>> &visited){
            
            if((nextX>=0&& nextX<n) && (nextY>=0 && nextY<n) && 
                mat[nextX][nextY] ==1 && visited[nextX][nextY] == 0){
                
                return 1;
            }
            else{
                return 0;
            }
    }
  
    void solve(int x, int y,vector<vector<int>> &mat, int n, vector<string> &ans,
    vector<vector<bool>> &visited, string path){
        //BASE CASE
        if(x == n-1 && y== n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        // DOWN
        if(isSafe(x+1,y ,n, mat, visited )){
            solve(x+1,y, mat, n, ans, visited, path+ 'D');
        }
        
        //LEFT
        if(isSafe(x,y-1 ,n, mat ,visited)){
            solve(x,y-1 , mat, n, ans, visited, path+ 'L');
        }
        
        //RIGHT
        if(isSafe(x,y+1 ,n,mat , visited)){
            solve(x,y+1, mat, n, ans, visited, path+ 'R');
        }
        
        // UP
        if(isSafe(x-1,y ,n, mat ,visited)){
            solve(x-1,y, mat, n, ans, visited, path+ 'U');
        }
            
        visited[x][y] = 0;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        
        if(mat[0][0] == 0){
            ans.push_back("-1");
            return ans;
        }
        
        int n = mat.size();
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        
        solve(0 ,0 ,mat ,n, ans , visited, path);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends