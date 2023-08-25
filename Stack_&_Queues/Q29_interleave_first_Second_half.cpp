#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class ques29
{
    public:
    void interleave(queue<int>&q)
    {
        stack<int>s;
        int n=q.size();

        //step-1
        for(int i=0;i<n/2;i++)
        {
            s.push(q.front());
            q.pop();
        }

        //step-2
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        //step-3
        for(int i=0;i<n/2;i++)
        {
            int val=q.front();
            q.pop();
            q.push(val);
        }

        //step-4
        for(int i=0;i<n/2;i++)
        {
            s.push(q.front());
            q.pop();
        }

        //step 5 ->stack to queue

        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};

int main()
{
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    ques29 obj;
    obj.interleave(q);

    //print
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}