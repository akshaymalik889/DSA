#include<iostream>
using namespace std;

class ques6
{
    public:
    string countSay(int n)
    {
        //base case
        if(n==1)
        return "1";
        if(n==2)
        return "11";

        //bcoz prev string is needed for build next string
        string s="11";

        for(int i=3;i<=n;i++)
        {
            string temp="";
            //add delimeter to string
            s=s+'&';
            int c=1;
            for(int j=1;j<s.length();j++)
            {
                if(s[j]!=s[j-1])
                {
                    //add count of string in t
                    //also we have to convert int count in string
                    temp=temp+to_string(c);
                    temp=temp+s[j-1];
                    c=1;
                }
                else
                c++;
            }
            s=temp;
        }
        return s;
    }
};

int main()
{

    int n=5;
    ques6 q;
    string res=q.countSay(n);
    cout<<res<<endl;


    return 0;
}