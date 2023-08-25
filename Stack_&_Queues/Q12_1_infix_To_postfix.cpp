#include<iostream>
#include<stack>
using namespace std;


class ques12
{
    private:
    int prec(char c)
    {

        if (c == '^')
        return 3;
    
        else if (c == '/' || c == '*')
        return 2;
    
        else if (c == '+' || c == '-')
        return 1;
    
        else
        return -1;
    }

    public:
    string infix_to_postfix(string str)
    {
        
        stack<char> st; 
        string ans;
 
        for (int i = 0; i < str.length(); i++) 
        {
            char c = str[i];
 
        
            // if an operand, add it to output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans = ans + c;
 
        
            //if opening bracket ‘(‘, push it to the stack.
            else if (c == '(')
            st.push('(');
 
            // If closing ‘)’,
            // pop and add  to ans string from the stack
            // until an ‘(‘ is encountered.
            else if (c == ')')
            {
                while (st.top() != '(') 
                {
                    ans =ans + st.top();
                    st.pop();
                }
                st.pop();
            }
 
            // If operator: +,-,/,*
            else 
            {
                while (!st.empty() && prec(str[i]) <= prec(st.top())) 
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
 
        // Pop all the remaining elements from the stack
        while (!st.empty()) 
        {
            ans =ans + st.top();
            st.pop();
        }
 
        return ans;
    }
};

int main()
{
    string str="a+b*(d+e)";

    ques12 q;
    cout<<q.infix_to_postfix(str);

    return 0;
}