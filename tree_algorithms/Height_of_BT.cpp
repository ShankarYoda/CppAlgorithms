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

//height of binary tree

int height(struct Node* node){
         if(!node) return 0;
         int lh=height(node->left);
         int rh=height(node->right);
         return 1+max(lh,rh);