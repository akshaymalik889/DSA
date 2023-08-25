#include<iostream>
#include<stack>
using namespace std;


class ques7
{
    public:
    char* reverse_string(char *S,int len)
    {
        stack<char>s;
       char *a=new char[len];

        for(int i=0;i<len;i++)
        {   
            char ch=S[i];
            s.push(ch);
        }
    
        int i=0;
        while(!s.empty())
        {
            a[i]=s.top();
            s.pop();
            i++;
        }
        a[i]='\0';
        
        return a;
    }
};

int main()
{
    char S[]={'a','k','s','h','a','y'};
    int len=sizeof(S)/sizeof(S[0]);
    ques7 q;
    cout<<q.reverse_string(S,len);



    return 0;
}