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

class ques17
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


    //method-2 //without space

    Node* checkMiddle(Node*&head)
    {   
        Node*slow=head;
        Node*fast=head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow;
    }

    Node* reverse(Node*&head)
    {   
        Node*prev=NULL;
        Node*next=NULL;
        Node*cur=head;

        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    bool checkPalindromeORnot(Node*head)
    {
        if(head->next==NULL)
        return true;

        //STEP-1 find middle
        Node*middle=checkMiddle(head);

        //STEP-2 REVERSE LIST AFTER MIDDLE
        middle->next=reverse(middle->next);

        //STEP-3 check palindrome
        Node*temp1=head;
        Node*temp2=middle->next;

        while(temp2!=NULL)
        {
            if(temp1->data != temp2->data)
            {
                middle->next=reverse(middle->next);
                return 0;
            }
        
            temp1=temp1->next;
            temp2=temp2->next;
        }
        middle->next=reverse(middle->next);
        return 1;
    }
};

int main()
{
    Node* head=NULL;

    ques17 q;
    q.insertNode(head,1);
    q.insertNode(head,2);
    q.insertNode(head,2);
    q.insertNode(head,1);
    // q.insertNode(head,40);
    // q.insertNode(head,50);
    cout<<"Linked List created..."<<endl;
    q.traverseList(head);

    cout<<q.checkPalindromeORnot(head);

  

    return 0;
}