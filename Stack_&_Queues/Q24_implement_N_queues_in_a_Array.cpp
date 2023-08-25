#include<iostream>
#include<queue>
using namespace std;

class kqueue
{
    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    kqueue(int n,int k)
    {
        this->n=n;
        this->k=k;
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        next= new int[n];
        freespot=0;
        for(int i=0;i<k;i++)
        {
            front[i]=-1;
            rear[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;
    }

    void enqueue(int data,int q)
    {
        //overflow
        if(freespot==-1)
        {
            cout<<"No empty space"<<endl;
            return;
        }
        //step 1 find index
        int index=freespot;

        //step 2 update freespot
        freespot=next[index];

        //step 3 check wheter first element

        if(front[q-1]==-1)
        {
            front[q-1]=index;
        }

        else
        {
            //new element to previous element
            next[rear[q-1]]=index;
        }

        //step 4 update next
        next[index]=-1;

        //step 5 update rear
        rear[q-1]=index;

        //step 6 push element
        arr[index]=data;
    }
    
    int  dequeue(int q)
    {
        //underflow
        if(front[q-1]==-1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }

        //find index to pop
        int index=front[q-1];
        //front update after pop
        front[q-1]=next[index];

        //update now 2 freespot
        next[index]=freespot;
        freespot=index;
        
        return arr[index]; 
    }
};


int main()
{
    kqueue ob1(10,3);

    ob1.enqueue(10,1);
    ob1.enqueue(15,1);
    ob1.enqueue(20,2);
    ob1.enqueue(25,1);

    cout<<ob1.dequeue(1)<<endl;
    cout<<ob1.dequeue(2)<<endl;
    cout<<ob1.dequeue(1)<<endl;
    cout<<ob1.dequeue(1)<<endl;


    return 0;
}