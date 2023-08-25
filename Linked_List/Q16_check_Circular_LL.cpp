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

class ques16
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

    bool check_Circular(Node* head)
    {
        if(head==NULL)
        return true;

        Node* fast=head;
        Node* slow=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)
            return true;
        }
        return false;
    }

};

int main()
{
    Node* head=NULL;

    ques16 q;
    q.insertNode(head,10);
    q.insertNode(head,20);
    q.insertNode(head,30);
    q.insertNode(head,40);
    q.insertNode(head,50);
    cout<<"Linked List created..."<<endl;
    q.traverseList(head);

    cout<<q.check_Circular(head);

    return 0;
}