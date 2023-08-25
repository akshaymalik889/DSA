#include<iostream>
#include<vector>
using namespace std;


class Node
{
    public:
    int data;
    Node* next=NULL;
    Node* prev=NULL;

    Node(int val)
    {
        this->data=val;
        this->prev=NULL;
        this->next=NULL;
    }
};

class ques21
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
            cout<<"NULL->";
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

    vector<pair<int,int> >Find_Pairs(Node* head,int x)
    {
        vector<pair<int,int> >ans;

        Node* temp=head;

        Node* last=NULL;
        
        while(temp->next!=NULL)
        temp=temp->next;

        last=temp;
        temp=head;

        while(temp<last)
        {
            int sum=temp->data+last->data;

            if(sum==x)
            {
                ans.push_back({temp->data,last->data});
                temp=temp->next;
                last=last->prev;
            }

            else if(sum<x)
            temp=temp->next;

            else
            last=last->prev;
        }
        return ans;
    }
};

int main()
{
    Node* head=NULL;

    ques21 q;
    q.insertNode(head,1);
    q.insertNode(head,2);
    q.insertNode(head,4);
    q.insertNode(head,5);
    q.insertNode(head,6);
    q.insertNode(head,8);
    q.insertNode(head,9);

    cout<<"doubly Linked List Created..."<<endl;
    q.traverseList(head);


    vector<pair<int,int> >v=q.Find_Pairs(head,7);
    
    for(auto i:v)
    cout<<i.first<<" "<<i.second<<endl;

    return 0;
}