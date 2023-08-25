#include<iostream>
#include<math.h>
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


class ques30
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
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    

    long long  multiplyTwoLists (Node* l1, Node* l2)
    {
        long long num1=0,num2=0;
        long long int mod=pow(10,9)+7;
   
        while(l1!=NULL|| l2!=NULL)
        {
            if(l1!=NULL)
            {
                num1=(num1*10+(l1->data))%mod;
                l1=l1->next;
            }
       
            if(l2!=NULL)
            {
                num2=(num2*10+(l2->data))%mod;
                l2=l2->next;
            }
        }
        return (num1*num2)%mod;
    }
    
};

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    
    ques30 q;
    q.InsertNode(head1,3);
    q.InsertNode(head1,2);
    q.InsertNode(head2,2);
    // q.InsertNode(head2,40);
    // q.InsertNode(head2,50);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head1);
    q.traverseList(head2);
    
    cout<<q.multiplyTwoLists(head1,head2);


    return 0;
}