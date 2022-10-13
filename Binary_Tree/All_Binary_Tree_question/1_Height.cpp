
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

struct Node *newNode(int value)
{
	Node *n = new Node;
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
struct Node *insertValue(struct Node *root, int value,
						 queue<Node *> &q)
{
	Node *node = newNode(value);
	if (root == NULL)
		root = node;

	else if (q.front()->left == NULL)
		q.front()->left = node;
	else
	{
		q.front()->right = node;
		q.pop();
	}
	q.push(node);
	return root;
}
Node *createTree(int arr[], int n)
{
	Node *root = NULL;
	queue<Node *> q;
	for (int i = 0; i < n; i++)
		root = insertValue(root, arr[i], q);
	return root;
}

// funtion for height of the binary Tree

int Height_of_Binary_Tree(struct Node *root)
{
	if (root == NULL)
		return 0;
	int leftValue = Height_of_Binary_Tree(root->left);
	int rightValue = Height_of_Binary_Tree(root->right);
	return max(leftValue, rightValue) + 1;
}

int main()
{
	int arr[] = {10, 20, 40, 40, 50, 60, 90, 78, 34};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = createTree(arr, n);

	int Height = Height_of_Binary_Tree(root);
	cout << "height of the binary tree is " << Height << endl;
	return 0;
}
