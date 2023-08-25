#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node*  next;
    Node* prev;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class ques20
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
        newNode->prev=temp;
    }
    
    void traverseList(Node* head)
    {
        Node* temp=head;

        while(temp!=NULL)
        {        
            if(temp->prev==NULL)
            {
                cout<<"NULL->";
            }
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

    //Approach-1 ->iterative
    void reverse_Ap_1(Node* &head)
    {
        Node* temp=head;
        Node* prev=NULL;
        Node* next=NULL;

        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            temp->prev=next;
            // if(next!=NULL)
            // next->prev=temp;
            prev=temp;
            temp=next;
        }
        head=prev;
    }

    //Approach-2-> Recursive
    Node* reverse_Ap_2(Node* head)
    {
        if(head==NULL)
        return NULL;
        

        Node* temp=head->next;
        head->next=head->prev;
        head->prev=temp;

        //reached end
        if(head->prev==NULL)
        return head;

        return reverse_Ap_2(head->prev);
    }

};

int main()
{
    ques20 q;

    Node* head=NULL;
    q.insertNode(head,10);
    q.insertNode(head,20);
    q.insertNode(head,30);
    q.insertNode(head,40);
    //q.insertNode(head,50);

    q.traverseList(head);
   // q.reverse_Ap_1(head);
    head=q.reverse_Ap_2(head);
    q.traverseList(head);

    return 0;
}