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

class ques24
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
        cout<<endl;
    }

    void RotateList(Node* &head,int N)
    {
        if(head==NULL)
        return ;

        Node* temp=head;
        
        for(int i=1;i<=N && temp!=NULL;i++)
        temp=temp->next;

        temp->prev->next=NULL;
        temp->prev=NULL;
        Node* store=temp;

        while(temp->next!=NULL)
        temp=temp->next;

        temp->next=head;
        head->prev=temp;
        head=store;
        
    }

};

int main()
{
    ques24 q;

    Node* head=NULL;
    q.insertNode(head,1);
    q.insertNode(head,2);
    q.insertNode(head,3);
    q.insertNode(head,4);
    q.insertNode(head,5);
    // q.insertNode(head,8);
    // q.insertNode(head,9);
    cout<<"linked list created.."<<endl;

    q.traverseList(head);

   int N=3;
   q.RotateList(head,N);

   q.traverseList(head);

    return 0;
}