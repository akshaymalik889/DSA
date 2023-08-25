#include<iostream>
using namespace std;


class Node{

    public:
    int data;
    Node* next;
    Node*random;

    //creating parameterized consructor for initilize node while creating
    Node(int d)
    {
        this->data=d;
        this->next=NULL;

    }
};


void insertAttail(Node*&head,int d)
{
    
    Node*newNode=new Node(d);
   
    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void traverseList(Node *&head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node*findMid(Node*head)
{
    Node*slow=head;
    Node*fast=head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node*merge(Node*left,Node*right)
{
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;
    
    Node*ans=new Node(-1);
    Node*temp=ans;
    
    while(left!=NULL &&right!=NULL)
    {
        if(left->data<right->data)
        {
            temp->next= left;
            temp=left;
            left=left->next;
        }
       else
       {
           temp->next=right;
           temp=right;
           right=right->next;
       }
    } 
    
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    
    ans=ans->next;
    return ans;
}

Node*mergeSort(Node*&head)
{
    if(head==NULL || head->next==NULL)
        return head;

        //finding mid
      Node*mid=findMid(head);

        //divide in two halfs
        Node*left=head;
        Node*right=mid->next;
        mid->next=NULL;
        
       // sort both halfs recursively
        left=mergeSort(left);
        right=mergeSort(right);

        
        
        //merge both left and right halfes
        
      Node*result=merge(left,right);
        
        return result;

        
}

int main()
{   
    //creating object in heap
    Node* node1=new Node(7);

    Node*head=node1;
  
    insertAttail(head,13);
    insertAttail(head,11);
    insertAttail(head,10);
    insertAttail(head,1);


    traverseList(head);

    Node*result=mergeSort(head);
    traverseList(result);
    
    return 0;
}
