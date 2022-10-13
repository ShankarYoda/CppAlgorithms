// Nitesh Kumar
// 05/10/22

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* newNode(int value)
{
	Node* n = new Node;
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
struct Node* insertValue(struct Node* root, int value,
						queue<Node *>& q)
{
	Node* node = newNode(value);
	if (root == NULL) root = node;

	
	else if (q.front()->left == NULL) q.front()->left = node;
   else {
		q.front()->right = node;
		q.pop();
	}
   q.push(node);
	return root;
}
Node* createTree(int arr[], int n)
{
	Node* root = NULL;
	queue<Node*> q;
	for (int i = 0; i < n; i++)
	root = insertValue(root, arr[i], q);
	return root;
}




// funtion for height of the binary Tree
/*

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Please leetcode for question https://leetcode.com/problems/same-tree/

*/

 bool helper_funtion(struct Node *p,struct Node *q)
    {
         if(p==NULL and q==NULL)  return true;
        if(p==NULL || q==NULL) return false;
       
      bool leftCall=  helper_funtion(p->left,q->left);
      bool rightCall=  helper_funtion(p->right,q->right);
        if(leftCall && rightCall && (p->data==q->data)) return true;
        
        return false;
       
        
    }
    bool isSameTree(struct Node* p, struct Node* q) {
      return helper_funtion(p,q);  
    }

 int main()
{
	int arr1[] = { 10, 20,40, 40, 50, 60 ,90,78,34};
	int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[]={10,20,40,40,50,60,90,78};
    int m=sizeof(arr2)/sizeof(arr2[0]);
	Node* root1 = createTree(arr1,n);
    Node *root2=createTree(arr2,m);
    if(isSameTree(root1,root2)) cout<<"Both tree are same tree" <<endl;
    else cout<<"Both the trees are not same"<<endl;
	
   
	return 0;
}
