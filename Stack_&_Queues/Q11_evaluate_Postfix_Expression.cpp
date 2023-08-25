#include<iostream>
#include<stack>
using namespace std;


class ques11
{
    public:
    int evaluate_Expression(string str)
    {
        
        stack<int>st;
        
        for(int i=0;i<str.length();i++)
        {
            if(isdigit(str[i]))
            st.push(str[i]-'0');
            
            else
            {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();

                switch(str[i])
                {
                    case '+': st.push(val2+val1);
                            break;
                    
                    case '-': st.push(val2-val1);
                            break;

                    case '*': st.push(val2*val1);
                            break;
                    
                    case '/': st.push(val2/val1);
                            break;
                }
            }
        }
        return st.top();

    }
};

int main()
{
    string str="231*+9-";

    ques11 q;
    cout<<q.evaluate_Expression(str);
    

    return 0;
}