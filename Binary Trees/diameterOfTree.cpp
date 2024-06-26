struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  private:
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int count = max(left, right)+ 1;
        return count;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        //Base Case
        if(root == NULL){
            return 0;
        }
        int leftDia = diameter(root->left);
        int rightDia = diameter(root->right);
        int combination = height(root->left)+ height(root->right)+ 1;
        int cnt = max(leftDia, max(rightDia , combination));
        return cnt;
        
    }
};