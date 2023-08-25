#include<iostream>
#include<bits/stdc++.h>
//#include<map>
using namespace std;



class Node{

    public:
    int data;
     Node* next;
     Node*random;

     //creating parameterized consructor for initilize node while creating
     Node(int d)
     {
        this->data=d;
        this->next=NULL;
        this->random=NULL;

     }
};


void insertAttail(Node*&head,int d,Node*rand)
{
    
    Node*newNode=new Node(d);
    newNode->random=rand;

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void traverseList(Node *&head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<"data:"<<temp->data<<" ";
        
        if(temp->random==NULL)
        cout<<"random:NULL ";
        else
        cout<<"random:"<<temp->random->data<<" ";

        if(temp->next==NULL)
        cout<<"next:NULL ";
        else
        cout<<"next:"<<temp->next->data<<" ";

        temp=temp->next;
    }
    cout<<endl;

}

//Approach 1: (by use two loops)
Node*Clone_Approach1(Node*&head)
{
    Node*temp=head;
    Node*head2=NULL;

    while(temp!=NULL)
    {
        Node*check=head;
        //traverseList(head2);
        if(temp->random==NULL)
        {
            insertAttail(head2,temp->data,NULL);
            temp=temp->next;
            continue;
        }

        while(check!=temp->random)
        {
            check=check->next;
        }

        insertAttail(head2,temp->data,check);

        temp=temp->next;

    }

    return head2;
}

//Approach-2 using map and store original and clone nodes

Node*Clone_Approach2(Node*&head)
{
    //step 1:CREATE A CLONE LIST

    Node*clonehead=NULL;
    Node*temp1=head;

    while(temp1!=NULL)
    {
        insertAttail(clonehead,temp1->data,NULL);
        temp1=temp1->next;
    }

    //traverseList(clonehead);

    //STEP 2:CREATE A MAP 

    unordered_map<Node*,Node*>m;
    temp1=head;
    Node*temp2=clonehead;

    //store original node and clone node in map
    while(temp1!=NULL && temp2!=NULL)
    {
        m.insert({temp1,temp2});
        temp1=temp1->next;
        temp2=temp2->next;
    }

    // for(auto it:m)
    // {
    //     cout<<"first:"<<it.first<<" second:"<<it.second<<endl;
    // }

    cout<<"hello"<<endl;
    temp1=head;
    temp2=clonehead;
    
    //STEP 3:SETTING CLONE NODE RANDOM POINTER
    while(temp1!=NULL)
    {
       
        // temp2->random=m[temp1->random];

        // temp1=temp1->next;
        // temp2=temp2->next;
        if(temp1->random==NULL)
        {
            temp2->random=NULL;
            temp1=temp1->next;
            temp2=temp2->next;
            continue;
        }

        auto it=m.find(temp1->random);
       // cout<<"\nfirst:"<<it->first<<" second:"<<it->second<<"\n";    
        temp2->random=it->first;
        
        temp1=temp1->next;
        temp2=temp2->next;

    }

    return clonehead;

}


Node*Clone_Approach3(Node*&head)
{
    Node*clonehead=NULL;

    Node*temp1=head;
    //STEP 1: CREATE CLONE LIST WITH DATA AND NEXT POINTER
    while(temp1!=NULL)
    {
        insertAttail(clonehead,temp1->data,NULL);
        temp1=temp1->next;
    }

    //traverseList(clonehead);


    temp1=head;
    Node*temp2=clonehead;
    Node*next1=NULL;
    Node*next2=NULL;

        //STEP 2: SET CLONE NODE BETWEEN ORIGINAL NODE
    while(temp1!=NULL && temp2!=NULL)
    {
        next1=temp1->next;
        temp1->next=temp2;
        temp1=next1;

        next2=temp2->next;
        temp2->next=temp1;
        temp2=next2;
    }

    //STEP 3: SET RANDOM POINTER IN CLONE LIST

    temp1=head;
    

    while(temp1!=NULL)
    {
        if(temp1->next!=NULL)
        {
            if(temp1->random!=NULL)
            temp1->next->random=temp1->random->next;

            else
            temp1->next->random=NULL;

        }

        temp1=temp1->next->next;
    }

    //STEP 4:REVERT CHANGES DONE IN STEP 2
    temp1=head;
    temp2=clonehead;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        temp1->next=temp2->next;
        temp1=temp1->next;

        if(temp1!=NULL)
        temp2->next=temp1->next;

        temp2=temp2->next;
    }

    //STEP 5: RETURN CLONEHEAD
        return clonehead;

}


int main()
{   
    //creating object in heap
    Node* node1=new Node(7);

    Node*head1=node1;
  
    insertAttail(head1,13,NULL);
    insertAttail(head1,11,NULL);
    insertAttail(head1,10,NULL);
    insertAttail(head1,1,NULL);

    //setting random pointers

    head1->random=NULL;
    head1->next->random=head1;
    head1->next->next->random=head1->next->next->next->next;
    head1->next->next->next->random=head1->next->next;
    head1->next->next->next->next->random=head1;
    
    traverseList(head1);

  // Node*head2=Clone_Approach1(head1);

   //traverseList(head2);
    //
    
    Node*head2=Clone_Approach2(head1);
    traverseList(head2);

    // Node*head2=Clone_Approach3(head1);
    // traverseList(head2);


    return 0;

}