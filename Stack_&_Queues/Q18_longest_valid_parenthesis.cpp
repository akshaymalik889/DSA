#include<iostream>
#include<stack>
using namespace std;


class ques_18
{
    public:
    int long_valid_paranthesis(string str)
    {
        stack<int>st;
        st.push(-1);

        int result=0;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
            st.push(i);

            else
            {
                //pop top element
                st.pop();


                if(!st.empty())
                {
                    result=max(result,i-st.top());
                }

                else
                st.push(i);
            }
        }
        return result;
    }
};


int main()
{
    string str="((()()";

    ques_18 q;
    cout<<q.long_valid_paranthesis(str);
    
    return 0;
}