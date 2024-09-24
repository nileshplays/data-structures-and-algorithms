#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char value){
        for(int i=0 ; i< 9; i++){
            //Row check
            if(board[row][i] == value)
                return false;
            //Col check
            if(board[i][col] == value)
                return false;
            
            //3*3 matrix check
            if(board[3*(row/3)+i/3][3*(col/3)+ i%3] == value){
                return false;
            }

        }
        return true;            
    }

    bool solve(vector<vector<char>> &board ){
        for(int i=0; i< 9; i++){
            for(int j =0; j< 9; j++){
                // EMPTY CELL
                if(board[i][j] == '.'){
                    for(int val= 1; val<=9 ; val++){

                        char ch = val+'0';
                        if(isSafe(i , j , board ,ch)){
                            board[i][j] = ch;
                            // Recursive call
                            bool futureSolPossible = solve(board);
                            if(futureSolPossible)
                                return true;
                            else{
                                //Backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};