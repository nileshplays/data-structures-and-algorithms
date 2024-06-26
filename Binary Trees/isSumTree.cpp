struct Node
{
    int data;
    Node* left, * right;
}; 
// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool,int> isSumTreeFast(Node* root){
        //Base Case
        if(root ==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        pair<bool,int> leftAns= isSumTreeFast(root->left);     
        pair<bool,int> rightAns= isSumTreeFast(root->right);     
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        bool condition = leftAns.second + rightAns.second == root->data;
        
        pair<bool,int> ans;
        if(left&&right && condition){
            ans.second = 2*root->data;
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};