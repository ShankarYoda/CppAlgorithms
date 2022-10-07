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
//minimum time to burn a BT
Node* find(Node* root,int target)
    {
        if(!root) return NULL ;
        if(root->data==target) return root;
        Node* l= find(root->left,target);
        if(l!=NULL) return l;
        return find(root->right,target);
    }
    void parent_Map(Node* root,map<Node*,Node*>&parent)
    {
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left) 
            {
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    
    int minTime(Node* root, int target) 
    {
      map<Node*,Node*> parent;
      parent_Map(root,parent);
      map<Node*,bool> visited;
      Node* tar=find(root,target);
      queue<Node*> q;
      q.push(tar);
      visited[tar]=1;
      
      int maxi=0;
      while(!q.empty())
      {
          int n=q.size();
          int flag=0;
          for(int i=0;i<n;i++)
          {
              Node* temp=q.front();
              q.pop();
              if(temp->left && !visited[temp->left])
              {
                  visited[temp->left]=1;
                  q.push(temp->left);
                  flag=1;
              }
              if(temp->right && !visited[temp->right])
              {
                  visited[temp->right]=1;
                  q.push(temp->right);
                  flag=1;
              }
              if(parent[temp] && !visited[parent[temp]])
              {
                  visited[parent[temp]]=1;
                  q.push(parent[temp]);
                  flag=1;
              }
          }
          if(flag) maxi++;
      }
      return maxi;
    }