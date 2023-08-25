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


class ques6
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

    Node* removeDuplicate(Node*&head)
    {
        if(head==NULL)
        return head;
    
        Node* temp=head;
    
        while(temp->next!=NULL)
        {
            if(temp->data==temp->next->data)
            {
                if(temp==head)
                {
                    head=head->next;
                    free(temp);
                    temp=head;
                }
                else
                {
                    Node* store=temp->next;
                    temp->next=temp->next->next;
                    free(store);
                }
            }
            else
            temp=temp->next;
        } 
        return head;
    }

};

int main()
{
    Node* head=NULL;
    
    ques6 q;
    q.InsertNode(head,10);
    q.InsertNode(head,20);
    q.InsertNode(head,20);
    q.InsertNode(head,20);
    q.InsertNode(head,30);
    q.InsertNode(head,40);
    q.InsertNode(head,40);
    q.InsertNode(head,50);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);
    head=q.removeDuplicate(head);
    q.traverseList(head);


}