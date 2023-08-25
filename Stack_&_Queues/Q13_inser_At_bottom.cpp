#include<iostream>
#include<stack>
using namespace std;


class ques13
{
    public:
   void insert_at_bottom(stack<int>&s,int x)
    {
        if(s.empty())
        {
            s.push(x);
            return;
        }   

        int val =s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(val);
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

    int x=100;

    ques13 q;
    q.insert_at_bottom(s,x);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}