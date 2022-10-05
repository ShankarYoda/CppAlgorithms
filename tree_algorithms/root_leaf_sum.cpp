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
// root to leaf sum 
bool hasPathSum(Node *root, int S) {
    if(root==NULL) return false;
    if(S<0) return false;
    if(root->data==S && !root->left && !root->right) return true;
    return  hasPathSum(root->left,S-root->data) || hasPathSum(root->right,S-root->data);
}