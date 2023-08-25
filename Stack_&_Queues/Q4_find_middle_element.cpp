#include<iostream>
#include<stack>
using namespace std;


class ques4
{
    private:
    int solve(stack<int>&s,int size,int i)
    {
        if(i==size/2)
        {
            return s.top();
        }

        int val=s.top();
        s.pop();
        int ans= solve(s,size,i+1);
        s.push(val);
        return ans;
    }

    public:
    int find_middle(stack<int>s)
    {
        int size=s.size();
        int i=0;
        int ans;

        return solve(s,size,i);
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

    ques4 q;
    cout<<q.find_middle(s);

    return 0;
}
