#include<iostream>
#include<vector>
#include<queue>
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

class compare
{
    public:
    bool operator()(Node*a,Node*b)
    {
        return a->data > b->data;
    }
};

class ques29
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

    Node* mergeKlists(vector<Node*>lists)
    {
        priority_queue<Node*,vector<Node*>,compare> pq;
    
        int k=lists.size();
        if(k==0)
        return NULL;
        
        //step 1: push starting elment of all list in min heap
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
    
        //step2:
        Node*head=NULL;
        Node*tail=NULL;
        
        while(!pq.empty())
        {
            Node*temp=pq.top();
            pq.pop();
        
            if(temp->next!=NULL)
            {
                pq.push(temp->next);
            }
        
            if(head==NULL)
            {
                //answer linked list is empty
                head=temp;
                tail=temp;
            }
            else
            {
                //insert at end of linked list
                tail->next=temp;
                tail=temp;
            }    
        }
        return head;
    }
   
};

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    Node* head3=NULL;

    ques29 q;
    q.insertNode(head1,1);
    q.insertNode(head1,4);
    q.insertNode(head1,5);
    q.insertNode(head2,1);
    q.insertNode(head2,3);
    q.insertNode(head2,4);
    q.insertNode(head3,2);
    q.insertNode(head3,6);
    cout<<"Linked List created..."<<endl;
    q.traverseList(head1);
    q.traverseList(head2);
    q.traverseList(head3);

    vector<Node*>Lists={head1,head2,head3};
    Node* head=q.mergeKlists(Lists);
    q.traverseList(head);

  

    return 0;
}