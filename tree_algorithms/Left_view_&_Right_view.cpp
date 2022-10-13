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
// left view of BT
vector<int> leftView(Node *root)
{ 
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
      int n=q.size();
      for(int i=1;i<=n;i++)
      {
          Node* temp=q.front();
          q.pop();
          if(i==1)
          {
              ans.push_back(temp->data);
          }
          if(temp->left !=NULL) q.push(temp->left);
          if(temp->right !=NULL) q.push(temp->right);
      }
    }
    return ans;
}
//Right view of BT
vector<int> rightView(Node *root)
    {
        vector<int> ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           for(int i=0;i<n;i++)
           {
               Node* temp=q.front();
               q.pop();
               if(i==n-1) ans.push_back(temp->data);
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
       }
       return ans;
    }