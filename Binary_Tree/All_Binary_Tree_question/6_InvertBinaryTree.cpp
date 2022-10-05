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
/*

Invert the binary tree 


*/
/////
////

void levelOrder(struct Node* root)
{
	if (root == NULL) return;
	queue<Node*> n;
	n.push(root);
	while (!n.empty()) {
		cout << n.front()->data << " ";
		if (n.front()->left != NULL) n.push(n.front()->left);
		if (n.front()->right != NULL) n.push(n.front()->right);
		n.pop();
	}
}
void InvertBinaryTree(struct Node *root)
{
    if(root==NULL) return ;
    InvertBinaryTree(root->left);
    InvertBinaryTree(root->right);
    // swap the left addres and right addres of the binary tree
    swap(root->left,root->right);
}



int main()
{
	int arr[] = { 10, 20,40, 40, 50, 60 ,90,78,34};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node* root = createTree(arr, n);
    levelOrder(root);
    cout<<endl;
    InvertBinaryTree(root);
    cout<<"Level order of binary tree after inverting the binary tree"<<endl;
    levelOrder(root);
   
    
    

	return 0;
}
