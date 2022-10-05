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

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

for  more details please refer https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


// Happy coding

*/

void solve(struct Node *root, int h, int v, map<int, map<int, multiset<int>>> &m)
{
    if (root == NULL)
        return;
    m[h][v].insert(root->data);
    solve(root->left, h - 1, v + 1, m);
    solve(root->right, h + 1, v + 1, m);
}
vector<vector<int>> verticalTraversal(struct Node *root)
{
    vector<vector<int>> v;
    map<int, map<int, multiset<int>>> m;
    solve(root, 0, 0, m);
    for (auto it : m)
    {
        vector<int> col;
        for (auto q : it.second)
            col.insert(col.end(), q.second.begin(), q.second.end());
        v.push_back(col);
    }
    return v;
}

int main()
{
    int arr[] = {10, 20, 40, 40, 50, 60, 90, 78, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTree(arr, n);
    cout << "Vertical traversal of binary tree" << endl;
    vector<vector<int>> res = verticalTraversal(root);
    for (auto it : res)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
