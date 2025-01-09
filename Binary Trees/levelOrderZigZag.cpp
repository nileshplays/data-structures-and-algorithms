
#include<bits/stdc++.h>
using namespace std;
 
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void levelOrder(TreeNode* root, vector<vector<int>> &ans){
        if(root == NULL) 
            return;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levEle;

            for(int i=0 ;i<levelSize; i++){
                TreeNode* temp = q.front();
                q.pop();
                levEle.push_back(temp->val);
                
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            if (!flag) {
                reverse(levEle.begin(), levEle.end());
            }

            flag = !flag;
            ans.push_back(levEle);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        return ans;
    }
};