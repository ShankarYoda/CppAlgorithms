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
//boundary traversal 
void left_node(Node* root,vector<int> &ans){
        if(!root) return;
        if(root->left)
        {
            ans.push_back(root->data);
            left_node(root->left,ans);
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            left_node(root->right,ans);
        }
    }
    void leaf(Node* root,vector<int> & ans)
    {
        if(!root)return;
        leaf(root->left,ans);
        if(!root->left && !root->right) ans.push_back(root->data);
        leaf(root->right,ans);
    }
    void right_node(Node* root,vector<int>&ans)
    {
        if(!root) return;
        if(root->right)
        {
            right_node(root->right,ans);
            ans.push_back(root->data);
        }
      else if(root->left)
      {
          right_node(root->left,ans);
          ans.push_back(root->data);
      }
    }