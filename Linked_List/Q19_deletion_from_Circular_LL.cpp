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


class Ques19
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
        temp=temp->next;

        temp->next=newNode;
    }

    void TreverseList(Node* head)
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void Delete_Circular(Node* &head,int val)
    {
        //finding last Node
        Node* last=head;

        while(last->next!=head)
        last=last->next;

    
    //case-1
        if(head==NULL)
        return;

    //case-2

        //if head
        if(val==head->data)
        {
            Node* store=head;
            head=head->next;

            last->next=head;

            free(store);
            return;
        }

    //case -3
        //other Nodes
        Node*temp=head;
        Node* prev=head;

        while(temp->data!=val)
        {
            prev=temp;
            temp=temp->next;
        }

        //if middle nodes
        if(temp!=last)
        {
            prev->next=temp->next;
            free(temp);
        }
        //if last node
        else
        {
            prev->next=head;
            last=prev;
            free(temp);
        }

    }
};

int main()
{
    Node* head=NULL;

    Ques19 q;
    q.insertNode(head,10);
    q.insertNode(head,20);
    q.insertNode(head,30);
    q.insertNode(head,40);
    q.insertNode(head,50);
    cout<<"LINKED LIST CREATED..."<<endl;

    //making circular
    Node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=head;

    //q.TreverseList(head);

    q.Delete_Circular(head,10);

    cout<<"deleted..."<<endl;

    //making Normal
    Node* last=NULL;
    temp=head;

    while(temp->next!=head)
    temp=temp->next;

    last=temp;
    last->next=NULL;

    q.TreverseList(head);
    return 0;
}