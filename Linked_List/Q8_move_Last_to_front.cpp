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


class ques2
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

    void Move_last_Front(Node* &head)
    {
        if(head==NULL || head->next==NULL)
        return ;
        
        Node* temp=head;
        Node* prev=head;

        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }

        prev->next=NULL;
        temp->next=head;
        head=temp;
    }
};

int main()
{
    Node* head=NULL;
    
    ques2 q;
    q.InsertNode(head,10);
    q.InsertNode(head,20);
    q.InsertNode(head,30);
    q.InsertNode(head,40);
    q.InsertNode(head,50);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);

    q.Move_last_Front(head);
    q.traverseList(head);
}