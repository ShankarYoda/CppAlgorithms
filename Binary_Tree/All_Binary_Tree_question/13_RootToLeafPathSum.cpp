// Nitesh Kumar
// 0/610/22
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};

// tree code creation code common in every code
//////
//////
///////
////
struct Node *newNode(int value)
{
	Node *n = new Node;
	n->data = value;
	n->left = n->right = NULL;
	return n;
}
// insert tree values
struct Node *insertValue(struct Node *root, int value, queue<Node *> &q)
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

//////
/////////
/////
////
/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.


*/

bool isLeaf(struct Node *root)
{
	if (root->left == NULL and root->right == NULL)
		return true;
	return false;
}
int s = 0;
void solve(struct Node *root, vector<int> &temp, vector<vector<int>> &ans, int t)
{
	if (root == NULL)
		return;
	temp.push_back(root->data);
	if (isLeaf(root))
	{
		s += root->data;

		if (s == t)
			ans.push_back(temp);
		s -= root->data;
		temp.pop_back();
		return;
	}
	s += root->data;

	solve(root->left, temp, ans, t);
	solve(root->right, temp, ans, t);
	s -= root->data;
	temp.pop_back();
}
vector<vector<int>> pathSum(struct Node *root, int t)
{
	vector<vector<int>> ans;
	vector<int> temp;
	solve(root, temp, ans, t);

	return ans;
}

int main()
{
	int arr[] = {10, 20, 10, 40, 50, 60, 90, 78, 34};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = createTree(arr, n);
	int targetSum = 0;
	cout << "Enter the targetSum vlaue" << endl;
	cin >> targetSum;
	vector<vector<int>> res = pathSum(root, targetSum);
	for (auto it : res)
	{
		for (auto i : it)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
