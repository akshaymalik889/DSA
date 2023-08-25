#include<iostream>
using namespace std;

class twoStack
{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    //constructor
    twoStack(int size)
    {
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }

    //functions

    void push1(int val)
    {
        if(top2-top1 > 1)
        {
            top1++;
            arr[top1]=val;
        }
    }

    void push2(int val)
    {
        if(top2-top1 > 1)
        {
            top2--;
            arr[top2]=val;
        }
    }

    int pop1()
    {
        if(top1>=0)
        {
            int ans=arr[top1];
            top1--;
            return ans;
        }

        else
        return -1;
    }

    int pop2()
    {
        if(top2<size)
        {
            int ans=arr[top2];
            top2++;
            return ans;
        }

        else
        return -1;
    }


};


int main()
{
    twoStack s(5);

    s.push1(10);
    s.push2(50);
    s.push1(20);
    s.push2(40);
    cout<<s.pop1();
    cout<<s.pop2();

    return 0;
}