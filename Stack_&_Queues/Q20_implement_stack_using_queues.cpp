#include<iostream>
#include<stack>
#include<queue>

using namespace std;


class MyStack 
{
public:

    //Approach-1
    queue<int>q1;
    queue<int>q2;

    //Approch-2
    queue<int>q;
    
    void push(int x)
    {
        // //Approach-1
        // q1.push(x);

        // while(!q2.empty())
        // {
        //     q1.push(q2.front());
        //     q2.pop();
        // }

        // swap(q1,q2);

        //Approach-2
        q.push(x);
        int size=q.size()-1;

        while(size>0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    int pop() 
    {
        // //Approach-1
        // if(q2.empty())
        // return -1;

        // else
        // {
        //     int ans=q2.front();
        //     q2.pop();
        //     return ans;
        // }


        //Approach-2
        if(q.empty())
        return -1;

        else
        {
            int ans=q.front();
            q.pop();
            return ans;
        }
    }
    
    int top() 
    {
        // //Approach-1
        // if(q2.empty())
        // return -1;

        // else
        // {
        //     return q2.front();
        // }

        // //Approach-2
        if(q.empty())
        return -1;

        else
        {
            return q.front();
        }
    }
    
    bool empty() 
    {
        // //Approach-1
        // if(q2.empty())
        // return true;

        // else
        // return false;

        //Approach-2
        if(q.empty())
        return true;

        else
        return false;
    }
};


int main()
{
    MyStack obj;

    obj.push(10);
    int first = obj.pop();
    int second= obj.top();
    bool third = obj.empty();

    cout<<first<<" "<<second<<" "<<third<<endl;

    return  0;
}