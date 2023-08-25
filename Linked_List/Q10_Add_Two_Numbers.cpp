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
        
    Node* Add_2_Numbers(Node* head1,Node* head2)
    {
        head1=reverse(head1);
        head2=reverse(head2);
        
        int carry=0;
        Node* temp1=head1;
        Node* temp2=head2;
        Node* prev1=temp1;
        
        while(temp1!=NULL && temp2!=NULL)
        {
            int sum=temp1->data+temp2->data+carry;
            
            if(sum>9)
            {
                int rem=sum%10;
                carry=sum/10;
                
                temp1->data=rem;
            }
            else
            {
                temp1->data=sum;
                carry=0;
            }
            
            prev1=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL)
        {
            int sum=temp1->data+carry;
            
             if(sum>9)
            {
                int rem=sum%10;
                carry=sum/10;
                
                temp1->data=rem;
            }
            else
            {
                temp1->data=sum;
                carry=0;
            }
            
            prev1=temp1;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            int sum=temp2->data+carry;
            
            if(sum>9)
            {
                int rem=sum%10;
                carry=sum/10;
                
                Node* newNode=new Node(rem);
                prev1->next=newNode;
                prev1=newNode;
            }
            else
            {
                Node* newNode=new Node(sum);
                carry=0;
                prev1->next=newNode;
                prev1=newNode;
            }
            
            temp2=temp2->next;
        }
        
        if(carry>0)
        {
            Node* newNode=new Node(carry);
            prev1->next=newNode;
        }
        
        head1=reverse(head1);
        return head1;
    }
};

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    
    ques10 q;
    q.InsertNode(head1,9);
    q.InsertNode(head1,9);
    q.InsertNode(head2,1);
    q.InsertNode(head2,2);
    q.InsertNode(head2,3);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head1);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head2);

    head1=q.Add_2_Numbers(head1,head2);
    cout<<"Addition list Created"<<endl;
    q.traverseList(head1);

   
}