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

/*

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes




*/
bool isLeaf(struct Node *root)
{
    if(root->left==NULL and root->right==NULL) return true;
    return false;
}
   void leftBoundary(struct Node *root,vector<int>&res)
   {
       struct Node *cur=root->left;
       while(cur)
       {
           if(!isLeaf(cur)) res.push_back(cur->data);
           if(cur->left) cur=cur->left;
           else cur=cur->right;
       }
   }
   void rightBoundary(struct Node *root,vector<int>&res)
   {
       vector<int>temp;
       struct Node *cur=root->right;
       while(cur)
       {
          
           if(!isLeaf(cur)) temp.push_back(cur->data);
           if(cur->right) cur=cur->right;
           else cur=cur->left; 
       }
       for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
   }
   void leafBoundary(struct Node *root,vector<int>&res)
   {
      
       if(isLeaf(root)) 
       {
           res.push_back(root->data);
           return ;
       }
       if(root->left) leafBoundary(root->left,res);
       if(root->right) leafBoundary(root->right,res);
   }
vector<int> Boundary_Traversal(struct Node *root)
{
     vector<int>res;
       if(root==NULL) return res;
       if(!isLeaf(root)) res.push_back(root->data);
       leftBoundary(root,res);
      leafBoundary(root,res);
       rightBoundary(root,res);
       return res;
}




int main()
{
	int arr[] = { 10, 20,40, 40, 50, 60 ,90,78,34};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node* root = createTree(arr, n);
	vector<int>ans=Boundary_Traversal(root);
	cout<<"Bouondary Traversal"<<endl;
	for(auto it:ans)
	{
		cout<<it<<" ";
	
	}
   
    
    

	return 0;
}
