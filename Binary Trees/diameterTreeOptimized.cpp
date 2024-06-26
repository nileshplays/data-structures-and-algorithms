 pair<int,int> diameterFast(Node* root){
        //Base Case
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int leftDia = left.first;
        int rightDia = right.first;
        int combination = left.second+right.second+1;
        pair<int,int> ans;
        ans.first = max(leftDia, max(rightDia, combination));
        ans.second = max(left.second, right.second) +1;
        
        return ans;
    }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        return diameterFast(root).first;
    