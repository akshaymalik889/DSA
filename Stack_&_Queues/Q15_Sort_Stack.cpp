#include<iostream>
#include<stack>

using namespace std;

class ques15
{
    private:
    void sortInserted(stack<int>&s,int x)
    {
        if(s.empty() || (!s.empty() && s.top()<x) )
        {
            s.push(x);
            return;
        }

        int num=s.top();
        s.pop();
        sortInserted(s,x);
        s.push(num);
    }

    public:
   
   void sortStack(stack<int>&s)
    {
        if(s.empty())
        return;

        int num=s.top();
        s.pop();
        sortStack(s);

        sortInserted(s,num);


    }

    void traverseStack(stack<int>&s)
    {
        if(s.empty())
        return;

        int num=s.top();
        cout<<num<<" ";
        s.pop();
        traverseStack(s);
        s.push(num);
    }


};


int main()
{

    ques15 q;
    stack<int>s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);


    q.traverseStack(s);
    cout<<endl;
   
   q.sortStack(s);
    q.traverseStack(s);
    
    
    


    return 0;
}