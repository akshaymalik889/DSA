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


Node*getTail(Node*head)
{
   Node*temp=head;

   while(temp!=NULL && temp->next!=NULL)
   {
       temp=temp->next;
   }
   return temp;
}

Node*partition(Node*head,Node*tail)
{
   Node*pivot=head;
   Node*curr=head->next,*prev=head;

   while(curr!=tail->next)
   {
       if(pivot->data>curr->data)
       {
           swap(prev->next->data,curr->data);
           prev=prev->next;
       }
       curr=curr->next;
   }
   swap(prev->data,pivot->data);
   return prev;
}
void solveSort(Node*head,Node*tail)
{
   if(head==NULL || tail==NULL || head==tail)
    return;
   
   Node*pivot=partition(head,tail);
   solveSort(head,pivot);
   solveSort(pivot->next,tail);
   
}


void quickSort(Node*&head)
{
    if(head==NULL || head->next==NULL)
    return;
   
    Node*tail=getTail(head);
    solveSort(head,tail); 
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

    quickSort(head);
    traverseList(head);
    
    return 0;
}
