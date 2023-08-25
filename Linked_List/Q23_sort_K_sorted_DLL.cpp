#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Node
{
    public:
    int data;
    Node*  next;
    Node* prev;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class ques23
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
            {
                cout<<"NULL->";
            }
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

    //Approach-3 using min heap

    struct compare
    {
        bool operator()(Node* first,Node* second)
        {
            return first->data > second->data;
        }
    };

    Node* Ksorted(Node* &head,int k)
    {   
        if(head==NULL)
        return head;

        priority_queue<Node*,vector<Node*>,compare> pq;

        Node* head2=NULL;
        Node* temp2=NULL;
        
        Node* temp=head;
        
        //push in min head (k+1)
        for(int i=0; temp!=NULL && i<=k ;i++)
        {
            pq.push(temp);
            temp=temp->next;
        }

        //check one by one frome heap
        while(!pq.empty())
        {
            if(head2==NULL)
            {
                head2=pq.top();
                head2->prev=NULL;
                temp2=head2;
            }
            else
            {
                temp2->next=pq.top();
                pq.top()->prev=temp2;
                temp2=pq.top();
            }
            pq.pop();

            if(temp!=NULL)
            {
                pq.push(temp);
                temp=temp->next;
            }   
        }
        temp2->next=NULL;
        return head2;
    }

};

int main()
{
    ques23 q;

    Node* head=NULL;
    q.insertNode(head,3);
    q.insertNode(head,6);
    q.insertNode(head,2);
    q.insertNode(head,12);
    q.insertNode(head,56);
    q.insertNode(head,8);
    //q.insertNode(head,9);
    cout<<"linked list created.."<<endl;

    q.traverseList(head);

    int k=2;

    Node* head2=q.Ksorted(head,k);
    q.traverseList(head2);

    return 0;
}