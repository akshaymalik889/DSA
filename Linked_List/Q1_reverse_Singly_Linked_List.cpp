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


class ques1
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
    
    // Approach-1 -> ITERATIVE
    void reverse_Ap_1(Node* &head)
    {

        Node* temp=head;
        Node* prev=NULL;
        Node* next=NULL;

        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        head=prev;
    }

    //Approach-2 ->Recursive
    Node* reverse_Ap_2(Node* head)
    {
        if(head==NULL || head->next==NULL)
        return head;

        Node* newHead=reverse_Ap_2(head->next);
       head->next->next=head;
       head->next=NULL;

        return newHead;
    }
};

int main()
{
    Node* head=NULL;
    
    ques1 q;
    q.InsertNode(head,10);
    q.InsertNode(head,20);
    q.InsertNode(head,30);
    q.InsertNode(head,40);
    q.InsertNode(head,50);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);
   // q.reverse_Ap_1(head);
   head=q.reverse_Ap_2(head);
   q.traverseList(head);

    return 0;
}