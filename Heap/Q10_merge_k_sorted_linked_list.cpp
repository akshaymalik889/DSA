#include<iostream>
#include<queue>
#include<vector>

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

void insertAtlast(Node*head,int d)
{
    Node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newNode=new Node(d);
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

class compare
{
    public:
    bool operator()(Node*a,Node*b)
    {
        return a->data > b->data;
    }
};

class ques10 {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        
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
    Node* head1=new Node(10);
    insertAtlast(head1,20);
    insertAtlast(head1,30);
    insertAtlast(head1,40);

    Node*head2=new Node(20);
    insertAtlast(head2,30);
    insertAtlast(head2,40);
    insertAtlast(head2,50);

    traverseList(head1);
    traverseList(head2);

    vector<Node*>v;
    v.push_back(head1);
    v.push_back(head2);

    ques10 q;
    head1=q.mergeKLists(v);
    traverseList(head1);
    



    return 0;
}