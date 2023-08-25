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

class ques31
{
    public:

    void insertAtlast(Node* &head,int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        else
        {
            Node* temp=head;
            
            while(temp->next!=NULL)
            temp=temp->next;

            temp->next=newNode;
        }
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

    Node* reverse(Node* head)
    {
        if(head==NULL)
        return head;
        
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
        return prev;
    }

    Node* deleteGreater(Node* head)
    {

        //step-1 reverse
        head=reverse(head);
        
        //step-2 delete right side greater
        Node* temp=head;
        Node* prev=head;
        int max=temp->data;
        
        while(temp!=NULL)
        {
            if(temp->data < max)
            {
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
            }
            else
            {
                max=temp->data;
                prev=temp;
                temp=temp->next;
            }
        }
        //step-3 reverse again
        head=reverse(head);
        return head;
    }
};

int main()
{
    Node* head=NULL;

    ques31 q;
    q.insertAtlast(head,12);
    q.insertAtlast(head,15);
    q.insertAtlast(head,10);
    q.insertAtlast(head,11);
    q.insertAtlast(head,5);
    q.insertAtlast(head,6);
    q.insertAtlast(head,2);
    q.insertAtlast(head,3);

    cout<<"linked list created..."<<endl;

    q.traverseList(head);

    head=q.deleteGreater(head);
    q.traverseList(head);
}