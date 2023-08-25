#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class specialStack
{
    public:
    stack<int>s;
    int mini=INT_MAX;

    void push(int data)
    {
        //for first element
        if(s.empty())
        {
            s.push(data);
            mini=data;
        }
        else
        {
            if(data<mini)
            {
                int val = 2*data - mini;
                s.push(val);
                mini=data; 
            }
            else
            s.push(data);
        }
    }

    int pop()
    {
        //overflow condition
        if(s.empty())
        return -1;

        int cur=s.top();
        s.pop();

        if(cur>mini)
        return cur;

        else
        {
            int prev=mini;
            int val = 2*mini - cur;
            mini=val;

            return prev;
        }
    }

    int top()
    {
        if(s.empty())
        return -1;

        int cur=s.top();

        if(cur<mini)
        return mini;

        else
        return cur;
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if(s.empty())
        return -1;

        else
        return mini;
    }
};


int main()
{
    specialStack s;
    cout<<s.getMin()<<endl;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getMin()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getMin()<<endl;

    return 0;
}