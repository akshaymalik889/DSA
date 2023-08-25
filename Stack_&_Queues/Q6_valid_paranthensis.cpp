#include<iostream>
#include<stack>
using namespace std;

class ques6
{
    public:
    bool valid_paranthesis(string s)
    {
        stack<char>st;

        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];

            if(ch=='{' || ch=='[' || ch=='(')
            st.push(ch);        

            else
            {
                if(st.empty())
                return false;

                else if( (ch==']' && st.top()=='[') || (ch==')' && st.top()=='(') || (ch=='}' && st.top()=='{') )
                st.pop();

                else
                return false;
            }
        }
        if(st.empty())
        return true;

        else
        return false;
    }
};


int main()
{
    string s="{([})}";

    ques6 q;
    cout<<q.valid_paranthesis(s);


    return 0;
}