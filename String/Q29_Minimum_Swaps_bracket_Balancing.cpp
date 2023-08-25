#include<iostream>
using namespace std;


class ques29
{
    public:
    int minimum_swaps(string S)
    {
        int openBrackets = 0;
        int closeBrackets = 0;
        int ans = 0;
        
        for(auto i : S)
        {
            if(i == ']')
            closeBrackets++;
            
            else
            {
                if(closeBrackets > openBrackets)
                {
                    ans =ans + closeBrackets - openBrackets;
                }
                openBrackets++;
            }
        }
        return ans;
    }
};


int main()
{
    string S="[]][][";

    ques29 q;
    cout<<q.minimum_swaps(S);

    return 0;
}