#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void addSolutions(vector<vector<int>> board, vector<vector<string>> &ans, int n){

        vector<string> temp;
        for(int i=0; i< n; i++){
            string str="";
            for(int j=0; j< n; j++){
                if(board[i][j] != 0){
                    str += 'Q';
                }
                else{
                    str +=".";
                }
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
        return;
    }

    bool isSafe(int row ,int col, vector<vector<int>> board, int n){

        int x = row;
        int y = col;
        // SAME Row Checking for iits left's side
        while(y >=0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }

        x = row;
        y= col;
        // UPPER DIagonal
        while(x>=0 && y>= 0){
            if(board[x][y] ==1)
                return false;
            x--;   // for upper diagonal x-1 & y-1
            y--;
        }
        // LOWER DIAGONAL
        x = row;
        y = col;
        while(x <n && y>=0){
            if(board[x][y] == 1)
                return false;
            
            x++;   // for lower diagonal x+1 & y-1
            y--;
        }
        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<int>>& board, int n){
        //BASE CASE
        if( col == n){
            addSolutions(board, ans, n);
            return;
        }

        //SOLVE 1 CASE
        for(int row =0 ;row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                // Recursion
                solve(col+1, ans, board , n);
                // After completion while Backtrack set that board's place 0 again
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // if(n==1){
        //     ans.push_back("Q");
        //     return ans;
        // }

        vector<vector<int>> board(n, vector<int> (n,0));
        solve(0, ans, board , n);

        return ans;
    }
};