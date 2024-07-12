/*
#include <bits/stdc++.h> 
using namespace std;
// Node structure which is used.

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~Node()
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}

};


void inorder(Node *root, vector<int> &v) {

  if (root) {

    inorder(root->left, v);

    v.push_back(root->data);

    inorder(root->right, v);

  }

}

 

int KthLargest(Node *root, int k) {

  vector<int> v;

  inorder(root, v);

  int n = v.size();

  if (k <= n) {

    return v[n - k];

  } 
  else {
    return -1;
  }
}
*/