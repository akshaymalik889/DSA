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

class singly_LL
{
    public:

    void insertAttail(Node* &head,int val)
    {
        //new node create
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

    void inserAthead(Node* &head,int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return ;
        }

        newNode->next=head;
        head=newNode;
    }

    void insertAtpos(Node* &head,int val,int pos)
    {
        if(pos==1)
        {
            inserAthead(head,val);
            return;
        }
        
        //Node created
        Node* newNode=new Node(val);

        Node* temp=head;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;

    }

    void deleteAthead(Node* &head)
    {
        if(head==NULL)
        return ;

        Node*temp=head;
        head=head->next;
        
        free(temp);
    }

    void deleteAttail(Node* &head)
    {
        if(head==NULL)
        {
            return;
        }

        Node* temp=head;
        Node* prev=head;
        
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        
        //if only single node in LL
        if(prev==temp)
        {
            deleteAthead(head);
            return;
        }

        //if multiple nodes
        prev->next=NULL;
        free(temp);
    }

    void deleteAtpos(Node* &head,int pos)
    {
        if(pos==1)
        {
            deleteAthead(head);
            return ;
        }

        Node* temp=head;
        Node* prev=head;

        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);

    }


    void display(Node* head)
    {
        Node* temp=head;

        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};


int main()
{
    Node* head=NULL;
    
    singly_LL s;
    s.insertAttail(head,1);
    //s.display(head);
    s.insertAttail(head,2);
    s.inserAthead(head,0);
    //s.display(head);
    s.inserAthead(head,-1);
    s.insertAttail(head,3);
    //s.display(head);
    s.insertAtpos(head,-2,1);
    //s.display(head);
    s.insertAtpos(head,10,3);
    //s.display(head);
    s.insertAtpos(head,50,8);
    //s.display(head);
    s.insertAtpos(head,40,8);
    //s.display(head);
    s.deleteAthead(head);
    s.deleteAttail(head);
    s.display(head);
    s.insertAttail(head,500);
    s.display(head);
    s.deleteAtpos(head,1);
    s.display(head);
    s.insertAtpos(head,30,1);
    s.display(head);
    s.deleteAtpos(head,2);
    s.display(head);
    s.deleteAtpos(head,7);
    s.display(head);
    s.insertAtpos(head,65,7);
    s.display(head);

    
}