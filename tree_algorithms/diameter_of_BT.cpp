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

//Diameter of BT
//first calculate the height
int height(Node* root,int &diameter)
    {
        if(!root) return 0;
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter, lh+rh+1);
        return 1+max(lh,rh);
    }
//use height func to find diameter
    int diameter(Node* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }