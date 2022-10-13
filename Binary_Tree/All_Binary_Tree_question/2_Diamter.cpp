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

/*
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them

for more please refer https://leetcode.com/problems/diameter-of-binary-tree/


*/
// funtion for Diameter  of the binary Tree
int solve(struct Node *root, int &maxwell)
{
    if (!root)
        return 0;
    int lh = solve(root->left, maxwell);
    int rh = solve(root->right, maxwell);

    maxwell = max(maxwell, lh + rh);
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(struct Node *root)
{
    int maxwell = 0;
    solve(root, maxwell);
    return maxwell;
}

int main()
{
    int arr[] = {10, 20, 40, 40, 50, 60, 90, 78, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTree(arr, n);

    int diameter = diameterOfBinaryTree(root);
    cout << "height of the binary tree is " << diameter << endl;
    return 0;
}
