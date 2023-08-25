#include<iostream>
#include<stack>

using namespace std;

class questions
{
    private:

    public:

    bool isRedudant(string str)
    {
        stack<char>s ;

        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];

            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            {
                s.push(ch);
            }

            else
            {
                //ch==')' or ch==lowercase letter(we ignore lowercase letters)
                if(ch==')' )
                {
                    bool isred=true;
                    while(s.top() != '(' )
                    {
                        char top=s.top();
                        if(top=='+' || top=='-' || top=='*' || top=='/')
                        {
                            isred=false;
                        }
                        s.pop();
                    }

                    if(isred==true)
                    return true;
                    
                    //for pop opening bracet we use pop here
                    s.pop();

                }
            }
        }  

        return false;
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

    questions q;
    
    string str="((a+b))";

    cout<<q.isRedudant(str);

   // q.traverseStack(s);
    
    
    


    return 0;
}