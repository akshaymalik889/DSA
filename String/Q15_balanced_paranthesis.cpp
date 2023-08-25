#include<iostream>
#include<stack>
using namespace std;

class ques15
{
    public:
    bool valid_paranthesis(string str)
    {
        stack<int>s;
        
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            
            if(ch=='(' || ch=='[' || ch=='{')
            s.push(ch);
            
            else
            {
                if(s.empty())
                return false;
                
                else if(( ch==')' && s.top()=='(' ) || ( ch==']' && s.top()=='[' ) || ( ch=='}' && s.top()=='{' ))
                s.pop();
                
                else
                return false;
            }
        }
        if(s.empty())
        return true;
        else
        return false;
    }
};

int main()
{
    string str="{([])}";

    ques15 q;
    cout<<q.valid_paranthesis(str);

    return 0;
}