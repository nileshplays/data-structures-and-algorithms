#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left =NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){//purana level complete traverse ho chuka he
            cout<<endl;
            if(!q.empty()){//Queue still has some child Nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp ->left);
            }
            if(temp->right){
                q.push(temp ->right);
            }
        }

    }
}

Node* insertIntoBST(Node* &root ,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data !=- 1){
        insertIntoBST(root , data);
        cin>>data;
    }
}

Node* minNode(Node* root){
    Node* temp = root;
    while(temp ->left != NULL){
        temp =temp->left;
    }
    return temp;
}
Node* maxNode(Node* root){
    Node* temp = root;
    while(temp ->right != NULL){
        temp =temp->right;
    }
    return temp;
}

Node* nodeToDeleteBST(Node* root, int d){
    if(root ==NULL)
        return NULL;
    
    if(root->data == d){
        // 0 child

        //1 child

        //2 child 
    }
    else if(root->data > d){ // Left me jao
        root->left =nodeToDeleteBST(root->left , d);
        return root;
    }
    else{
        root->right =nodeToDeleteBST(root->right , d);
        return root;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create the BST: "<<endl;
    takeInput(root);

    cout<<"Traversing Level Order Traversing:: "<<endl;
    levelOrderTraversal(root);

    int minVal = minNode(root)->data;
    cout<<"MIN Value: "<<minVal<<endl;
    int maxVal = maxNode(root)->data;
    cout<<"MAX Value: "<<maxVal<<endl;
}