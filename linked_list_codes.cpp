//Singly Linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    //destructor
    ~Node(){
        int value=this -> data;
        //memory free
        if(this -> next!=NULL){
            delete next;
            this -> next=NULL;
        }
        cout<<"Memory freed for node with data: "<<value<<endl;
    }

};

void insertAtHead(Node* &head,int d){
    //creating new node
    Node* temp= new Node(d);

    temp -> next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    //creating new node
    Node* temp= new Node(d);

    tail -> next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at start
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;

    while(count<position-1){
        temp= temp -> next;
        count++;
    }

    //insert at tail
    if(temp -> next==NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d
    Node* nodetoinsert= new Node(d);
    nodetoinsert -> next= temp -> next;
    temp -> next= nodetoinsert;
}

void deletenode(Node* &head,int pos){
    //deleting first or start node
    if(pos==1){
        Node* temp=head;
        head=head -> next;
        //free start node
        temp -> next=NULL;
        delete temp;
    }

    else{
        //deleting any middle or last node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next=curr -> next;
        curr -> next= NULL;
        delete curr;
    }
}

void print(Node* &head){
    if(head ==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    Node* temp=head;

    while(temp!= NULL){
        cout<<temp -> data<<" ";
        temp=temp -> next;
    }
    cout<<endl;
}

int main(){
    //creating a new node
    Node* node1= new Node(100);
    //cout<<node1 -> data<<endl;
    //cout<<node1 -> next<<endl;

    //head pointing to new node
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertAtHead(head,12);
    print(head);

    insertAtHead(head,0);
    print(head);

    insertAtTail(tail,9);
    print(head);

    insertAtPosition(head,tail,4,69);
    print(head);

    cout<<"head: "<<head -> data<<endl;
    cout<<"tail: "<<tail -> data<<endl;

    deletenode(head,5);
    print(head);

    cout<<"head: "<<head -> data<<endl;
    cout<<"tail: "<<tail -> data<<endl;

    return 0;
}


//Doubly linked list
/*
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val=this -> data;

        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with data: "<<val<<endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    // insertion at start
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // insertion at tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deletenode(Node* &head,int pos){
    //deleting first or start node
    if(pos==1){
        Node* temp=head;
        temp -> next -> prev=NULL;
        head=temp -> next;
        temp -> next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr -> next;
            count++;
        }

        curr -> prev=NULL;
        prev -> next=curr -> next;
        curr -> next=NULL;
        delete curr;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlen(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout<<getlen(head)<<endl;;

    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 7);
    print(head);

    insertAtTail(tail, 8);
    print(head);

    insertAtPos(head, tail, 3, 0);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deletenode(head,6);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}
*/


//Circular linked list
/*
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data=d;
        this -> next=NULL;
    }

    //DESTRUCTOR
    ~Node(){
        int val=this -> data;

        if(this -> next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with value: "<<val<<endl;
    }
};

void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        newnode -> next=newnode;
    }

    //non-empty list
    else{
        Node* curr=tail;

        while(curr -> data!=element){
            curr=curr -> next;
        }

        //element found
        Node* temp =new Node(d);
        temp -> next=curr -> next;
        curr -> next=temp;
    }
}

void deleteNode(Node* &tail,int element){
    //empty list
    if(tail==NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }

    else{
        Node* prev=tail;
        Node* curr=prev -> next;

        while(curr -> data!=element){
            prev=curr;
            curr=curr -> next;
        }

        prev -> next=curr -> next;
        //1 node ll
        if(prev ==curr){
            tail = NULL;
        }

        //>=2 node ll
        else if(tail==curr){
            tail=prev;
        }

        curr -> next=NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp=tail;

    //empty list
    if(tail==NULL){
        cout<<"List is empty!"<<endl;
    }

    do{
        cout<<tail -> data<<" ";
        tail=tail -> next;
    }while(tail!=temp);
    cout<<endl;
}

int main(){
    Node* tail=NULL;

    insertNode(tail,5,1);
    print(tail);

    insertNode(tail,1,2);
    print(tail);
    
    insertNode(tail,2,4);
    print(tail);

    insertNode(tail,2,3);
    print(tail);

    deleteNode(tail,1);
    print(tail);
}
*/