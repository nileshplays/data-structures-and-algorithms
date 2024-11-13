//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    long long int solveTop(int n, vector<int> &dp){
        
        long long int mod =1e9+7; 
        if(n<=1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = (solveTop(n-1,dp) + solveTop(n-2,dp))%mod;
        return dp[n];
        
    }
    
    long long int topDown(int n) {
        // code here
        vector<int> dp(n+1,-1); 
        return solveTop(n,dp);
    }
    
    
    long long int bottomUp(int n) {
        // code here
        long long int mod =1e9+7;
        vector<int> dpp(n+1);
        dpp[0] = 0;
        dpp[1] = 1;
        
        for(int i =2; i<= n; i++){
            dpp[i] = (dpp[i-1] + dpp[i-2])%mod;
        }
        return dpp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends