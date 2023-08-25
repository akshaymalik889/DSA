#include<iostream>
#include<stack>
using namespace std;

class ques20
{
    public:
    int minimum_bracket(string s)
    {

        //if odd length ->ans not possible
        if(s.length()%2!=0)
        return -1;

        //even length
        stack<char>st;

        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];

            if(ch=='{')
            st.push(ch);

            //close bracket
            else
            {
                if(!st.empty() && st.top()=='{')
                st.pop();

                else
                st.push(ch);

            }
        }

        //stack contain invalid expression

        int a=0,b=0;
        while(!st.empty())
        {
            if(st.top()=='{')
            a++;
            else
            b++;

            st.pop();
        }

        int ans=(a+1)/2 + (b+1)/2;
        return ans;
    }
};

int main()
{
    string s="}{{}}{{{";

    ques20 q;
    cout<<q.minimum_bracket(s);

    return 0;
}