#include<iostream>
#include<unordered_map>
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


class ques7
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
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    //Approach-1
    void sort_0_1_2_App_1(Node*&head)
    {
        Node*temp=head;
        int zeroCount=0;
        int oneCount=0;
        int twoCount=0;

        while(temp!=NULL)
        {
            if(temp->data==0)
            zeroCount++;

            else if(temp->data==1)
            oneCount++;

            else
            twoCount++;

            temp=temp->next;
        }

        temp=head;

        while(temp!=NULL)
        {
            if(zeroCount>0)
            {
                temp->data=0;
                zeroCount--;
            }
        
            else if(oneCount>0)
            {
                temp->data=1;
                oneCount--;
            }
    
            else if(twoCount>0)
            {
                temp->data=2;
                twoCount--;
            }
            temp=temp->next;
        }

}


//Approach_2

    void Sort2_0_1_2_App_2(Node*&head)
    {
        if(head==NULL)
        return ;

        Node*temp=head;

        Node*zeroHead=new Node(-1);
        Node*zeroTail=zeroHead;
        Node*oneHead= new Node(-1);
        Node*oneTail=oneHead;
        Node*twoHead=new Node(-1);
        Node*twoTail=twoHead;

        while(temp!=NULL)
        {   
            if(temp->data==0)
            {
                zeroTail->next=temp;
                zeroTail=zeroTail->next;
            }

            if(temp->data==1)
            {
                oneTail->next=temp;
                oneTail=oneTail->next;
            }

            if(temp->data==2)
            {
                twoTail->next=temp;
                twoTail=twoTail->next;
            }

            temp=temp->next;
        }

        if(oneHead->next!=NULL)
        {
            zeroTail->next=oneHead->next;
        }
        else
        {
            zeroTail->next=twoHead->next;
        }

        oneTail->next=twoHead->next;
        twoTail->next=NULL;
    
        head=zeroHead->next;
    }

    
};

int main()
{
    Node* head=NULL;
    
    ques7 q;
    q.InsertNode(head,1);
    q.InsertNode(head,2);
    q.InsertNode(head,2);
    q.InsertNode(head,1);
    q.InsertNode(head,2);
    q.InsertNode(head,0);
    q.InsertNode(head,2);
    q.InsertNode(head,2);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);

    // q.sort_0_1_2_App_1(head);
    // q.traverseList(head);

    q.Sort2_0_1_2_App_2(head);
    q.traverseList(head);
   

}