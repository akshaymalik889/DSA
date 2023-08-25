#include<iostream>
using namespace std;


//implement using array

class circularQueue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    //constructor
    circularQueue(int size)
    {
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void push(int val)
    {
        //queues is full
        if( (rear+1)%size ==front )
        {
            cout<<"queue is full"<<endl;
        }

        //first element pushed
        else if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            arr[rear]=val;
            cout<<"element pushed"<<endl;
        }
        
        //cyclic nature
        else
        {
            rear=(rear+1)%size;
            arr[rear]=val;
            cout<<"element pushed"<<endl;
        }
    }

    int pop()
    {
        //check empty or not
        if(front==-1 && rear==-1)
        {
            cout<<"queue is empty";
            return -1;
        }

        //if single element only
        else if(front==rear)
        {
            int ans=arr[front];
            arr[front]=-1;
            front=-1;
            rear=-1;
            cout<<"element popped";
            return ans;
        }

        // Normal case + top maintains cyclic nature
        else
        {
            int ans=arr[front];
            arr[front]=-1;
            front=(front+1)%size;
            cout<<"element popped";
            return ans;
        }
        
    }
};

//implement using Linked List
    class Node
    {
        public:
        int data;
        Node *next;

        Node(int data)
        {
            this->data=data;
            next=NULL;
        }
    };

    class Linkedlist
    {
        public:
        Node* front;
        Node* rear;

        //constructor
        Linkedlist()
        {
            front=NULL;
            rear=NULL;
        }

        void enqueue(int val)
        {
            Node* newNode=new Node(val);

            //if empty
            if(rear==NULL)
            {
                front=newNode;
                rear=newNode;

                rear->next=front;
                cout<<"element pushed"<<endl;
            }
            else
            {
                rear->next=newNode;
                rear=newNode;
                rear->next=front;
                cout<<"element pushed"<<endl;
            }
        }

        int dequeue()
        {
            Node* temp=front;

            //if empty
            if(front==NULL && rear==NULL)
            {
                cout<<"already empty";
                return -1;
            }

            //single node only
            else if(front==rear)
            {
                int ans=front->data;
                front=NULL;
                rear=NULL;
                free(temp);
                cout<<"element popped:";
                return ans;
            }

            else
            {
                int ans=front->data;
                front=front->next;
                rear->next=front;
                free(temp);
                cout<<"element popped:";
                return ans;
            }
        }
    };

int main()
{
    // circularQueue q(5);

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // cout<<q.pop()<<endl;
    // q.push(60);
    
    Linkedlist l;

    l.enqueue(10);
    l.enqueue(20);
    l.enqueue(30);
    l.enqueue(40);
    l.enqueue(50);
    cout<<l.dequeue()<<endl;
    l.enqueue(60);
    cout<<l.dequeue()<<endl;
    return 0;
}