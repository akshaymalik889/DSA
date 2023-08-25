#include<iostream>
using namespace std;

class ques9
{
    public:
    void all_subsequence(string str,string ans,int i)
    {
        //base case
        if(i>=str.length())
        {
            cout<<ans<<" ";
            return ;
        }

        //pick
        ans=ans+str[i];
        all_subsequence(str,ans,i+1);

        //not pick
        ans=ans.substr(0,ans.length()-1);
        all_subsequence(str,ans,i+1);
    }
};

int main()
{
    string str="abc";
    string ans="";

    ques9 q;
    q.all_subsequence(str,ans,0);


    return 0;
}