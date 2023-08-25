#include<iostream>
#include<stack>
#include<queue>
using namespace std;


class ques28
{
    public:
    void reversefirstK(queue<int>&q,int k)
    {
        stack<int>s;
   
        //step-1
        for(int i=0;i<k;i++)
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
        int n=q.size();

        for(int i=0;i<n-k;i++)
        {
            int val=q.front();
            q.pop();
            q.push(val);
        }

    }
};

int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k=3;

    ques28 obj;
    obj.reversefirstK(q,k);

    //print
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}