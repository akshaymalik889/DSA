#include<iostream>
using namespace std;


//implement queue using arrays

class queue
{
    public:
    int *arr;
    int size;
    int rear;
    int front;

    //constructor
    queue(int size)
    {
        this->size=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }

    //finctions

    void push(int val)
    {
        if(rear==size-1)
        cout<<"queue overflow"<<endl;

        //inserting 1st element
        else if(rear==-1 && front==-1)
        {
            front=0;
            rear=0;
            arr[rear]=val;
            cout<<"element pushed"<<endl;
        }
        
        //iserting further elements
        else
        {
            rear++;
            arr[rear]=val;
            cout<<"element pushed"<<endl;
        }
    }

    int pop()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"queue underflow";
            return -1;
        }
        
        //it means only last element left in queue
        else if(front==rear)
        {   
            int ans=arr[front];
            arr[front]=-1;
            front=-1;
            rear=-1;
            
            cout<<"element popped";
            return ans;
            
        }

        //delete further elements
        else
        {
            int ans=arr[front];
            arr[front]=-1;
            front++;

            cout<<"element popped";
            return ans;
        }
    }

    int peek()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"queue is empty";
            return -1;
        }
        
        else
        return arr[front];
    }

    bool isEmpty()
    {
        if(front==-1 && rear==-1)
        return true;

        else
        return false;
    }

    int sizee()
    {
        return rear-front + 1;
    }

};

//implement queue using linked list

class Node
{
    public:
    int data;
    Node* next;

    //constuctor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Linkedlist
{
    public:
    Node* front;
    Node* rear;
    int size;


    //constructor
    Linkedlist()
    {
        size=0;
    }

    //functions

    void push(int val)
    {
        Node* temp=new Node(val);

        if(front==NULL)
        {
            front=temp;
            rear=temp;
            size++;
            cout<<"element pushed"<<endl;
        }
        else
        {
            rear->next=temp;
            rear=temp;
            size++;
            cout<<"element pushed"<<endl;
        }
    }

    int pop()
    {
        if(front==NULL)
        {
            cout<<"queue underflow"<<endl;
            return -1;
        }
        else
        {
            int ans=front->data;
            front=front->next;
            size--;
            cout<<"element pooped";
            return ans;
        }
    }

    int peek()
    {
        if(front==NULL)
        {
            cout<<"queue is empty";
            return -1;
        }
        else
        {
            return front->data;
        }
    }


    bool isEmpty()
    {
        if(front==NULL)
        return true;

        else
        return false;
    }

    int sizee()
    {
        return size;
    }

};

int main()
{

    //using arrays

    queue q(5);
    
    cout<<q.peek()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.pop()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.sizee();

    //using Linkedlist
    Linkedlist l;

    cout<<"linked list......."<<endl;

    cout<<l.peek()<<endl;
    cout<<l.isEmpty()<<endl;
    cout<<l.pop()<<endl;
    l.push(10);
    l.push(20);
    l.push(30);
    cout<<l.peek()<<endl;
    cout<<l.pop()<<endl;
    cout<<l.peek()<<endl;
    cout<<l.sizee();

    return 0;
}