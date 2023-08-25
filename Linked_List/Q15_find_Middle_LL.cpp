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

class ques15
{
    public:

     void InsertNode(Node* &head,int val)
    {
        //create node
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
        // if(head==NULL)
        // {
        //     cout<<"empty list"<<endl;
        //     return ;
        // }

        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    Node* findMiddle(Node* head)
    {
        Node* fast=head;
        Node* slow=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow;
    }
};


int main()
{
    Node* head=NULL;
    
    ques15 q;
    q.InsertNode(head,10);
    q.InsertNode(head,20);
    q.InsertNode(head,30);
    q.InsertNode(head,40);
    q.InsertNode(head,50);
    q.InsertNode(head,60);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);

    cout<<q.findMiddle(head)->data;
}