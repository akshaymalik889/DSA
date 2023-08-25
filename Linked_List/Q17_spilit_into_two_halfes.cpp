#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};

class ques17
{
    public:
    void insertNode(Node* &head,int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void traverseList(Node* head)
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void spilit(Node* head,Node* &head1,Node* &head2)
    {
        Node* fast=head;
        Node* slow=head;
        Node* prev=head;
    
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
    
        if(fast==NULL)
        {
            prev->next=NULL;
            head1=head;
            head2=slow;
        }
    
        else if(fast!=NULL && fast->next==NULL)
        {
            head2=slow->next;
            slow->next=NULL;
            head1=head;
        }
    }

};

int main()
{
    Node* head=NULL;

    ques17 q;
    q.insertNode(head,1);
    q.insertNode(head,5);
    q.insertNode(head,7);
    // q.insertNode(head,40);
    // q.insertNode(head,50);
    cout<<"Linked List created..."<<endl;
    q.traverseList(head);

    Node* head1=NULL;
    Node* head2=NULL;

    q.spilit(head,head1,head2);

    q.traverseList(head1);
    q.traverseList(head2);
    

    return 0;
}