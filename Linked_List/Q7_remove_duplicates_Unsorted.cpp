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

    //Approach 1 (Using Two loops)

    Node* removeDuplicates_Ap_1(Node*&head)
    {
        if(head==NULL)
        return head;

        Node*cur=head;

        while(cur!=NULL && cur->next!=NULL)
        {
            Node*prev=cur;
            Node*temp=cur->next;

            while(temp!=NULL)
            {
                if(temp->data==cur->data)
                {
                    prev->next=temp->next;
                    temp=temp->next;
                }

                else
                {
                    prev=temp;
                    temp=temp->next;
                }
            }
            cur=cur->next;
        }
        return head;
    }


//Approacb 2: using Map

    Node* remove_duplicates_Ap_2(Node*&head)
    {
        if(head==NULL)
        return head;

        unordered_map<int,bool>m;

        Node*temp=head;
        Node*prev=NULL;

        while(temp!=NULL)
        {
            if(m.find(temp->data)!=m.end())
            {
                prev->next=temp->next;
                temp=temp->next;
            }
            else
            {
                m.insert({temp->data,true});
                prev=temp;
                temp=temp->next;
            }
        }

        // for(auto it:m)
        // {
        //     cout<<"data:"<<it.first<<"value:"<<it.second<<endl;
        // }
        return head;

    }


    
};

int main()
{
    Node* head=NULL;
    
    ques7 q;
    q.InsertNode(head,5);
    q.InsertNode(head,2);
    q.InsertNode(head,2);
    q.InsertNode(head,4);
    q.InsertNode(head,4);
    q.InsertNode(head,3);
    q.InsertNode(head,2);
    q.InsertNode(head,5);

    cout<<"Linked list Created"<<endl;
    q.traverseList(head);
   // q.removeDuplicates_Ap_1(head);
    q.remove_duplicates_Ap_2(head);
    q.traverseList(head);

}