#include<iostream>
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

class ques20
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

   Node* reverseBY_k(Node* head,int k)
   {
        if (head==NULL)
        return head;
        
        head->prev = NULL;

        Node *temp;
        Node* curr = head;
        Node* newHead=NULL;
        
        int count = 0;

        while (curr != NULL && count < k) 
        {
            newHead = curr;
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
            count++;
        }
 
        if (count >= k) 
        {
            Node* rest = reverseBY_k(curr, k);
            head->next = rest;
            
            if (rest != NULL)
            rest->prev = head;
        }
        return newHead;
   }

};

int main()
{
    ques20 q;

    Node* head=NULL;
    q.insertNode(head,1);
    q.insertNode(head,2);
    q.insertNode(head,3);
    q.insertNode(head,4);
    q.insertNode(head,5);
    q.insertNode(head,6);
    q.insertNode(head,7);
    q.insertNode(head,8);
    // q.insertNode(head,9);
    // q.insertNode(head,10);


    q.traverseList(head);

   head=q.reverseBY_k(head,3);
   head->prev=NULL;

    q.traverseList(head);



    return 0;
}