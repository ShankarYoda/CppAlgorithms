#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data=0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

 class Pair {
    public:
    Node *node=nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

//Display function
void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}


//Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}
int dia=0;



int diameter1(Node *root)
{
  // write your code here
  if(root==NULL){
     return -1;

  }

  int lh=diameter1(root->left);
  int rh=diameter1(root->right);

  int ht=max(lh,rh)+1;
  int diamnode=lh+rh+2;
  if(diamnode>dia){
     dia=diamnode;
  }   
  return ht;
}
class DiMover
{
  public:
  int dia=0;
};
int diameter2(Node* node,DiMover* dm){

   // write your code here
   if(node==NULL){
     return -1;

   }

   int lh=diameter2(node->left,dm);
   int rh=diameter2(node->right,dm);

   int ht=max(lh,rh)+1;
   int diamnode=lh+rh+2;
   if(diamnode>dm->dia){
     dm->dia=diamnode;
   }   
   return ht;
}

//third approcah and the bad one becauase it has time complexity = o(n^2) 
//rest all three apriaches has time complexity = o(n);
int diameter3(Node* node){
  if(node==NULL){
    return 0;
  }
  int lh=height(node->left);
  int rh=height(node->right);

  int ld=diameter3(node->left);
  int rd=diameter3(node->right);

  int nodediam=lh+rh+2;
  //diameter will the max of diameter of left ,diameter of right,diameter of root;
  return max(ld,max(rd,nodediam));

}

//4th approch
class DiaPair
{
  public:
  int ht=-1;
  int dia=0;
};
DiaPair* diameter4(Node* node){
  if(node==NULL){
    DiaPair* dnull=new DiaPair();
    dnull->ht=-1;
    dnull->dia=0;
    return dnull;
  }

  DiaPair* ldp=diameter4(node->left);
  DiaPair* rdp =diameter4(node->right);
  DiaPair* ans=new DiaPair();

  ans->ht=max(ldp->ht,rdp->ht)+1;
  ans->dia=max(ldp->dia,max(rdp->dia,ldp->ht+rdp->ht+2));
  return ans;



}
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } else {
        arr[i] = stoi(tmp);
      }
    }
    
    
    Node * root = constructTree(arr);

    int diam=0;
    DiMover* dee=new DiMover();
    dee->dia=0;
    // DiaPair* ddd=new DiaPair();

    DiaPair* ddd = diameter4(root);
    cout<<ddd->dia;
}
