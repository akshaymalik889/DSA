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

class ques32
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

    Node* segerate_Even_Odd(Node* head)
    {
        Node* temp=head;
        Node* odd=NULL;
        Node* even=NULL;
        Node* oddtemp=NULL;
        Node* eventemp=NULL;
        
        
        while(temp!=NULL)
        {
            //even
            if(temp->data %2 == 0)
            {
                if(even==NULL)
                {
                    even=temp;
                    eventemp=temp;
                }
                else
                {
                    eventemp->next=temp;
                    eventemp=temp;
                }
            }
            else //odd
            {
                if(odd==NULL)
                {
                    odd=temp;
                    oddtemp=temp;
                }
                else
                {
                    oddtemp->next=temp;
                    oddtemp=temp;
                }
            }
            temp=temp->next;
        }
        
        if(odd==NULL)
        return even;
        if(even==NULL)
        return odd;
        
        head=even;
        eventemp->next=odd;
        oddtemp->next=NULL;
        return head;
    }
};

int main()
{
    Node* head=NULL;

    ques32 q;
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
    head=q.segerate_Even_Odd(head);

    q.traverseList(head);
   
}