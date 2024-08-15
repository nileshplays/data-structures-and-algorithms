#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* createTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data; cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of: "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter data for inserting in right of: "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}
void inorder(Node* root , vector<int> &traverse){
    if(root == NULL)
        return;
    inorder(root->left , traverse);
    traverse.push_back(root->data);
    inorder(root->right , traverse);

}

void print(vector<int> traverse){
    for(auto i: traverse)
        cout<<i<<" ";
    cout<<endl;
}

void createMinHeap(Node* ){
    
}

int main(){
    vector<int> traverse;
    Node* root = NULL;
    root = createTree(root);
    inorder(root , traverse);
    print(traverse);
}