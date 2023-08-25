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

        
    Node*Kreverse(Node*&head,int k)
    {
        //base case
        if(head==NULL)
        return NULL;

        //STEP-1 Reverse First K Nodes
        Node*prev=NULL;
        Node*next=NULL;
        Node*cur=head;

        int count=0;

        while(cur!=NULL && count<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }

        //STEP 2: Recursion done rest part
        if(next!=NULL)
        head->next=Kreverse(next,k);


        //STEP 3: Return Head of reversed List
        return prev;
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

    head=q.Kreverse(head,3);
    q.traverseList(head);
}