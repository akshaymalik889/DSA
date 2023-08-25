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

    Node* reverse(Node* head)
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
        return prev;
    }

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

    Node* add1(Node* &head)
    {
        head=reverse(head);
        
        Node*prev=head;
        Node* temp=head;
        int carry=0;
        int val=1;
        
        while(temp!=NULL)
        {
            int sum=temp->data+val+carry;
            val=0;
            
            if(sum>9)
            {
                int rem=sum%10;
                carry=sum/10;
                temp->data=rem;
            }
            else
            {
                temp->data=sum;
                carry=0;
            }
            prev=temp;
            temp=temp->next;
        }
        
        if(carry>0)
        {
            Node* newNode=new Node(carry);
            prev->next=newNode;
        }
        head=reverse(head);
        return head;
    }
        
    
};

int main()
{
    Node* head=NULL;
    
    ques2 q;
    q.InsertNode(head,9);
    q.InsertNode(head,9);
    q.InsertNode(head,9);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);

    q.add1(head);
    q.traverseList(head);

    
}