#include<iostream>
#include<stack>
using namespace std;


class ques12
{
    private:
    bool isOperator(char x)
    {
        if(x=='+' || x=='-' || x=='*' || x=='/')
        return true;
        
        else
        return false;
    }

    public:
    string prefix_to_postfix(string str)
    {
        stack<string> s;

        int n = str.length();
 
        // reading from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // check if symbol is operator
            if (isOperator(str[i]))
            {
                // pop two operands from stack
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
 
                // concat the operands and operator
                string temp = op1 + op2 + str[i];
 
                // Push string temp back to stack
                s.push(temp);
            }
 
            // if symbol is an operand
            else
            {
            // push the operand to the stack  after convert into string
            s.push(string(1, str[i]));
            }
        }
        
        // stack contains only the Postfix expression
        return s.top();
    }
};

int main()
{
    string str="+a*bd";

    ques12 q;
    cout<<q.prefix_to_postfix(str);
    
    return 0;
}