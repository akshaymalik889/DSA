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


class ques3_To_5
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

    Node* findLoop(Node*&head)
    {
        if(head==NULL)
        {
            cout<<"List is empty..."<<endl;
            return NULL;
        }
    
        Node*fast=head;
        Node*slow=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
            {
                cout<<"Loop exist at:"<<slow->data<<endl;
                return slow ;
            }
        }
        cout<<"NO loop exist..."<<endl;
        return NULL;
    }

    Node* findBeginngloop(Node*&head)
    {
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return NULL;
        }

        Node*slow=findLoop(head);
        
        if(slow==NULL)
        {
            cout<<"NO loop Exist..."<<endl;
            return NULL;
        }

        Node*fast=slow;
        slow=head;
    
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        cout<<"begining loop Node:"<<slow->data<<endl;
        return slow;
    }

    void removeLoop(Node*&head)
    {
        if(head==NULL)
        {
            cout<<"list is empty.."<<endl;
            return ;
        }

        Node*begin=findBeginngloop(head);
        if(begin==NULL)
        {
            cout<<"NO loop exist.."<<endl;
            return;
        }

        Node*temp=begin;
        while(temp->next!=begin)
        {
            temp=temp->next;
        }   

        temp->next=NULL;

        cout<<"loop removed successfully..."<<endl;
    }
};

int main()
{
    Node* head=NULL;
    
    ques3_To_5 q;
    q.InsertNode(head,10);
    q.InsertNode(head,20);
    q.InsertNode(head,30);
    q.InsertNode(head,40);
    q.InsertNode(head,50);

    //create loop in singly linked list
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;

    cout<<"Linked list Created"<<endl;
    //q.traverseList(head);

    q.findLoop(head);
    q.findBeginngloop(head);
    q.removeLoop(head);
    q.traverseList(head);
}