#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class ques27
{
    public:

    //Approach-1 using stack
    void queueReversal_Ap1(queue<int>&q)
    {
        stack<int>s;
        while(!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        while(!s.empty())
        {
         q.push(s.top());
         s.pop();   
        }
    }

    //Approach-1 Recursion
    void queueReversal_Ap2(queue<int>&q)
    {
        if(q.empty())
        return;

        int top=q.front();
        q.pop();
        queueReversal_Ap2(q);
        q.push(top);
    }
};

int main()
{
    queue<int>q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    ques27 obj;

    //obj.queueReversal_Ap1(q);
    obj.queueReversal_Ap2(q);
    
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}