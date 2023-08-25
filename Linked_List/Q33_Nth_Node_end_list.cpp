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

class ques33
{
    public:

    void insertAtlast(Node* &head,int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        else
        {
            Node* temp=head;
            
            while(temp->next!=NULL)
            temp=temp->next;

            temp->next=newNode;
        }
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

    int getNthFromLast(Node *head, int n)
{
        Node *fast = head;
        Node *slow = head;

        // iterate first n nodes using fast
	    while(n-1>0 && fast!=NULL )
	    {
	        fast = fast -> next;
	        n--;
	    }
           

	    // if fast is already null, it means we have to delete head itself.
        //So, just return next of head
        if(fast==NULL) 
        return -1;

        // iterate till fast reaches the last node of list
	    while(fast -> next!=NULL) 
	    {
	        fast = fast -> next;
	        slow = slow -> next;  
	    }
	
       
        return slow->data;
}
   
};

int main()
{
    Node* head=NULL;

    ques33 q;
    q.insertAtlast(head,12);
    q.insertAtlast(head,15);
    q.insertAtlast(head,10);
    q.insertAtlast(head,11);
    q.insertAtlast(head,5);
    q.insertAtlast(head,6);
    q.insertAtlast(head,2);
    q.insertAtlast(head,3);

    cout<<"linked list created..."<<endl;

    q.traverseList(head);
    cout<<q.getNthFromLast(head,3);
    
   
}