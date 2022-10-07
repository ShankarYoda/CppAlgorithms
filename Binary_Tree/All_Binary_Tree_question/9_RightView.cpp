// Nitesh Kumar
// 05/10/22
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

/*
Given a Binary Tree, print left view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side
Input
                 1
               /   \
              2     3
             / \     \
            4   5     6
Output RightView
            10 
        20         40 
    40     50     60   90
 78   34    

 Level Order Representation
*/

void RightView_of_binary_tree(struct Node *root, vector<int> &RightView, int level)
{
    if (root == NULL)
        return;
    if (level == RightView.size())
        RightView.push_back(root->data); // traverse through the binary tree and make note of the level of the binary tree if the level is equal to array size then push the value into the ans array
    
    RightView_of_binary_tree(root->right, RightView, level + 1); // increase level+=1
    RightView_of_binary_tree(root->left, RightView, level + 1); // increase level+=1
}
int main()
{
    int arr[] = {10, 20, 40, 40, 50, 60, 90, 78, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTree(arr, n);
    vector<int> RightView;
    RightView_of_binary_tree(root, RightView, 0);
    cout << "left view of the binary tree" << endl;
    for (auto it : RightView)
        cout << it << " ";
    return 0;
}
