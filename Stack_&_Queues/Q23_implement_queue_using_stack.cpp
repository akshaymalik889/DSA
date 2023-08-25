#include<iostream>
#include<stack>
using namespace std;


class myQueue
{
    public:

    stack<int>s1;
    stack<int>s2;

    void push(int x) 
    {
        // //Approach-1 using two stacks
        // //step-1
        // while(!s1.empty())
        // {
        //     s2.push(s1.top());
        //     s1.pop();
        // }
    
        // //step-2
        // s1.push(x);
    
        // //step-3
        // while(!s2.empty())
        // {
        //     s1.push(s2.top());
        //     s2.pop();
        // }

        //Approach-2 using two stacks
        s1.push(x);
    }

    int pop() 
    {
        // //Approach-1 -> using two stacks
        // if(s1.empty())
        // return -1;
        
        // int ans=s1.top();
        // s1.pop();
        // return ans;

        //Approach-2 using two stacks
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            //means s1 already empty so s2 also empty
            if(s2.empty())
            return -1;

            else
            {
                int ans=s2.top();
                s2.pop();
                return ans;
            }
        }

        //s2 not empty
        else
        {
            int ans=s2.top();
            s2.pop();
            return ans;
        }
    }
    
    int peek() 
    {
        // //Approach-1 ->using two stacks
        // if(s1.empty())
        // return -1;
        // else
        // return s1.top();

        //Approach-2 using two stacks
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            int ans;
            //means s1 already empty so s2 also empty
            if(s2.empty())
            ans= -1;

            else
            {
                ans= s2.top();
            }

            //make  to its original position
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return ans;
        }

        //s2 not empty
        else
        {
            return s2.top();
        }
    }
    
    bool empty() 
    {
        // //Approach-1 ->using two stacks
        // if(s1.empty())
        // return true;

        // else
        // return false;

        //Approach-2 using two stacks
        if(s2.empty() && s1.empty() )
        return true;

        else
        return false;
    }

};


int main()
{
    myQueue obj;
    obj.push(10);
    int first = obj.pop();
    int second = obj.peek();
    bool third = obj.empty();

    cout<<first<<" "<<second<<" "<<third<<endl;

    return 0;
}