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


class ques10
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
        
    Node* Intersection_List(Node* head1,Node* head2)
    {
        Node* temp1=head1;
        Node* temp2=head2;
        Node* head3=NULL;
        Node*temp3=NULL;
    
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {   
                Node* newNode=new Node(temp1->data);
           
                if(head3==NULL)
                {
                    head3=newNode;
                    temp3=head3;
                }
                else
                {
                    temp3->next=newNode;
                    temp3=newNode;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
       
            else if(temp1->data < temp2->data)
            temp1=temp1->next;
       
            else
            temp2=temp2->next;
        }
        return head3;
    }
};

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    
    ques10 q;
    q.InsertNode(head1,1);
    q.InsertNode(head1,2);
    q.InsertNode(head1,3);
    q.InsertNode(head1,4);
    q.InsertNode(head1,6);
    q.InsertNode(head2,2);
    q.InsertNode(head2,4);
    q.InsertNode(head2,6);
    q.InsertNode(head2,8);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head1);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head2);

    Node* head3=q.Intersection_List(head1,head2);
    q.traverseList(head3);
   
}