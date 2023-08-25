#include<iostream>
using namespace std;


class ques37
{
    public:
    string Remove_Adjacent(string S)
    {
        int n=S.length();
        
        //base case
        if(n==0 || n==1)
        return S;
        
        //checking adjacent
        if(S[0]==S[1])
        {
            int index=0;
            while(S[index]==S[0] && index<n)
            {
                index++;
            }
            return S[0] + Remove_Adjacent(S.substr(index));
        }
        //not same
        return S[0] + Remove_Adjacent(S.substr(1));
    }
};


int main()
{
    string S="abzxxab";

    ques37 q;

    cout<<q.Remove_Adjacent(S);

    return 0;
}