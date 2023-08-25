#include<iostream>
using namespace std;

//stack implementation using arrays

class stack
{
    public:
    int* arr;
    int top;
    int size;

    //constructor
    stack(int s)
    {
        this->size=s;
        arr=new int[size];
        top=-1;
    }

    void push(int val)
    {
        if(size-top > 1)
        {
            top++;
            arr[top]=val;
            cout<<"element pushed"<<endl;
        }
        else
        cout<<"stack overflow"<<endl;
    }

    void pop()
    {
        if(top>=0)
        {
            top--;
            cout<<"element popped"<<endl;
        }
        else
        cout<<"stack underflow"<<endl;
    }

    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        

        else
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top==-1)
        return true;

        else
        return false;
    } 
};

//Implement stack using  linked list


class Node
{
    public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class Linkedlist
{
    public:
    Node*head;
    int size;

    //constructor
    Linkedlist()
    {
        head=NULL;
        size=0;
    }

    //functions

    void push(int val)
    {
        Node* temp;
        temp= new Node(val);

        temp->next=head;
        size++;
        head=temp;

        cout<<"element pushed"<<endl;
    }

    void pop()
    {
        if(head==NULL)
        cout<<"stack underflow"<<endl;
        
        else
        {
            Node* temp=head;
            head=head->next;
            free(temp);
            size--;
            cout<<"element popped"<<endl;
        }
    }

    int peek()
    {
        if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else
        return head->data;
    }

    bool isEmpty()
    {
        if(head==NULL)
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

    //stack using Array
    stack s(5);

    cout<<s.peek();
    cout<<s.isEmpty();
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek();
    s.pop();
    cout<<s.peek()<<endl;

    //Stack using linkedlist

    Linkedlist l;

    cout<<"linked list........."<<endl;
    cout<<l.isEmpty()<<endl;
    l.pop();
    l.push(10);
    l.push(20);
    l.push(30);
    cout<<l.peek()<<endl;
    l.pop();
    cout<<l.peek();


    return 0;
}