#include<iostream>
using namespace std;

class Nstacks
{
    public:
    int* arr;
    int* top;
    int* next;
    int freespot;

    //constructor
    Nstacks(int N,int S)
    {
        //N ->no of stacks
        //S ->size of array

        //give memory
        arr=new int[S];
        top=new int[N];
        next=new int[S];

        //initialize top to -1
        for(int i=0;i<N;i++)
        {
            top[i]=-1;
        }

        //initialize next to next free space
        for(int i=0;i<S;i++)
        {
            next[i]=i+1;
        }

        //initialize last index of next to -1
        next[S-1]=-1;

        //initialize freespot to 0
        freespot=0;
    }

    //Functions

    bool push(int x,int m)
    {
        //x ->element
        //m -> stack in which we have to insert

        //check overflow
        if(freespot==-1)
        return false;

        //step-1 ->find index
        int index=freespot;

        //step-2 ->insert element in array
        arr[index]=x;

        //step-3 ->update freespot
        freespot=next[index];

        //step-4 ->update next
        next[index]=top[m-1];

        //step-5 ->update top
        top[m-1]=index;

        return true;
    }

    int pop(int m)
    {
        //m ->stack in which we have to pop

        //check overflow
        if(top[m-1]==-1)
        return -1;

        //Steps -> for pop it reverse of push

        int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;

        freespot=index;

        return arr[index];
    }
};


int main()
{
    int n=3;
    int size=6;

    Nstacks s(n,size);

    cout<<s.push(10,1)<<endl;
    cout<<s.push(20,1)<<endl;
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;

    return 0;
}