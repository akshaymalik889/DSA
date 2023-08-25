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

class ques22
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

    int countTriplets(Node* &head,int x)
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        return 0;

        Node* tail=NULL;
        Node* temp=head;
        int count=0;


        //calculating tail first time
        while(temp->next!=NULL)
        temp=temp->next;

        tail=temp;
        temp=head;

        while(temp->next!=NULL)
        {
            Node* start=temp->next;
            Node* last=tail;
            
            int val=x-temp->data;

            while(start!=NULL && last!=NULL && start!=last && last->next!=start)
            {
                int sum=start->data+last->data;
                if(sum==val)
                {
                    count++;
                    start=start->next;
                    last=last->prev;
                }

                else if(sum<val)
                start=start->next;

                else
                last=last->prev;

            }
            temp=temp->next;
        }
        return count;

    }


};

int main()
{
    ques22 q;

    Node* head=NULL;
    q.insertNode(head,1);
    q.insertNode(head,2);
    q.insertNode(head,4);
    q.insertNode(head,5);
    q.insertNode(head,6);
    q.insertNode(head,8);
    q.insertNode(head,9);
    cout<<"linked list created.."<<endl;

    int x=17;
    q.traverseList(head);

    cout<<q.countTriplets(head,x);

    return 0;
}