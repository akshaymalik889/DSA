#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Doubly_LL
{
    public:

    void insertAtpos(Node* &head,int val,int pos)
    {
        //new Node
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        //insert at head
        if(pos==1)
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return;
        }

        Node* temp=head;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        
        //middle positions
        if(temp->next!=NULL)
        {
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next=newNode;
            newNode->next->prev=newNode;
            return;
        }

        //if last post
        temp->next=newNode;
        newNode->prev=temp;
    }

    void deleteAtpos(Node*&head,int pos)
    {
        if(head==NULL)
        return;

        //delete at head
        if(pos==1)
        {
            Node*temp=head;
            head=head->next;

            free(temp);
            if(head==NULL)
            return;

            else
            head->prev=NULL;

            return;
        }


        Node*temp=head;
        Node*p=head;

        for(int i=1;i<pos;i++)
        {
            p=temp;
            temp=temp->next;
        }

        //delete at middle
        if(temp->next!=NULL)
        {
            p->next=temp->next;
            temp->next->prev=p;
            free(temp);
            return;
        }

        //delete at end
        p->next=NULL;
        free(temp);

    }

    void traverseList(Node* head)
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            if(temp->prev==NULL)
            cout<<"NULL->";
            else
            cout<<temp->prev->data<<"->";

            cout<<temp->data<<"->";

            if(temp->next==NULL)
            cout<<"NULL ";
            else
            cout<<temp->next->data<<" ";

            temp=temp->next;
        }
    }
};


int main()
{
    Node* head=NULL;

    Doubly_LL d;
    d.insertAtpos(head,10,1);
    //d.traverseList(head);
    d.insertAtpos(head,20,1);
    //d.traverseList(head);
    d.insertAtpos(head,30,2);
    //d.traverseList(head);
    d.insertAtpos(head,40,3);
    //d.traverseList(head);
    d.insertAtpos(head,50,5);
    //d.traverseList(head);
    d.deleteAtpos(head,1);
    //d.traverseList(head);
    d.deleteAtpos(head,3);
    //d.traverseList(head);
    d.deleteAtpos(head,3);
    d.traverseList(head);

    


}