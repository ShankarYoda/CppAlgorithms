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

//zig-zag traversal
vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>ans;
    	if(!root) return ans;
    	queue<Node*> q;
    	int flag=1;
    	q.push(root);
    	while(!q.empty())
    	{
    	    int n=q.size();
    	     vector<int> res(n);
    	    for(int i=0;i<n;i++)
    	    {
    	    Node* temp=q.front();
    	    q.pop();
    	   
    	    int index=(flag)? i: (n-i-1);
    	    res[index]=temp->data;
    	    if(temp->left) q.push(temp->left);
    	    if(temp->right) q.push(temp->right);
    	    }
    	    flag=!flag;
    	    for(int i=0;i<n;i++)
    	    {
    	        ans.push_back(res[i]);
    	    }
    	}
    	return ans;
    }