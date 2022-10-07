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

///
////
///

void BFS(struct Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> n;
    n.push(root);
    while (!n.empty())
    {
        cout << n.front()->data << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
      
    }
}
/*

 The zigzag level order traversal of its nodes' values
  from left to right, then right to left for the next level and alternate between

*/
vector<vector<int>> zigzagLevelOrder(struct Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<struct Node *> q;
    int flag = 0;
    q.push(root);

    while (!q.empty())
    {
        vector<int> a;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            struct Node *temp = q.front();
            q.pop();
            a.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        flag++;
        if (flag % 2 == 0)
            reverse(a.begin(), a.end());
        ans.push_back(a);
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 40, 89, 50, 60, 90, 78, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTree(arr, n);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    cout<<"level order traversal"<<endl;
BFS(root);

cout<<"zig-zag Traversal "<<endl;
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
