// Nitesh Kumar
// 0/610/22
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};


// tree code creation code common in every code
//////
//////
///////
////
struct Node* newNode(int value)
{   Node* n = new Node;
	n->data = value;
	n->left =n->right = NULL;
	return n;
}
// insert tree values 
struct Node* insertValue(struct Node* root, int value, queue<Node *>& q)
{
	Node* node = newNode(value);
	if (root == NULL) root = node;
    else if (q.front()->left == NULL) q.front()->left = node;
   else { q.front()->right = node; 
        q.pop();
	}
   q.push(node);
	return root;
}
Node* createTree(int arr[], int n)
{   Node* root = NULL;
	queue<Node*> q;
	for (int i = 0; i < n; i++)
	root = insertValue(root, arr[i], q);
	return root;
}

//////
/////////
/////
////





// dfs traversal 
void inorder(struct Node *root)
{
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// preorder traversal
void preorder(struct Node *root)
{
    if(root==NULL) return ;
     cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// post order traversal
void postOrder(struct Node *root)
{
    if(root==NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{
	int arr[] = { 10, 20,40, 40, 50, 60 ,90,78,34};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node* root = createTree(arr, n);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postOrder(root);
    
    

	return 0;
}
