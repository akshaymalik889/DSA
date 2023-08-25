#include<iostream>
#include<stack>
using namespace std;


class ques14
{
    private:
    void insertAt_Bottom(stack<int>&s2,int val)
    {
        if(s2.empty())
        {
            s2.push(val);
            return ;
        }

        int x=s2.top();
        s2.pop();

        insertAt_Bottom(s2,val);

        s2.push(x);
    }

    public:
    void reverse_stack(stack<int>&s,stack<int>&s2)
    {
        if(s.size() > 0)
        {
            int val=s.top();
            s.pop();

            reverse_stack(s,s2);

            insertAt_Bottom(s2,val);
        }
        return;
    }

};


int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    stack<int>s2;

    ques14 q;
    q.reverse_stack(s,s2);

    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }

    return 0;
}