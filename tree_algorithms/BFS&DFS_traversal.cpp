#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//BFS Traversal or level order Traversal

vector<vector<int>> levelOrder(Node* node)
{
  vector<vector<int>> ans;
  queue<Node*> q;
  q.push(node);
  while(!q.empty())
  {
      int n=q.size();
      vector<int> v;
      for(int i=0;i<n;i++)
      {
          Node* temp=q.front();
          q.pop();
          v.push_back(temp->data);
          if(temp->left) {
           q.push(temp->left);   
          }
          if(temp->right)
          {
              q.push(temp->right);
          }
      }
      ans.push_back(v);
  }
  return ans;
}
//DFS or preorder traversal root-left-right

void solve(Node* root, vector<int> & ans)
{
    if(root!=NULL)
    {
        ans.push_back(root->data);
        solve(root->left,ans);
        solve(root->right,ans);
    }
}
vector <int> preorder(Node* root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}