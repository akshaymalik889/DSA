#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class ques16
{
    private:
    int solve(string str,vector<string>&words,unordered_map<string,int>&dp)
    {
        int n=str.length();
        
        //base case
        if(n==0)
        return 1;
        
        //check in dp first
        if(dp[str]!=0)
        return dp[str];
        
        //finding  string
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            string temp=str.substr(0,i);
            for(int j=0;j<words.size();j++)
            {
                //finding substring words vector
                if(temp.compare(words[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            
            //here we finding remaining string ex we find ab before,so here
            //we finding cde
            if(flag==1 && solve(str.substr(i,n-i),words,dp)==1)
            {
                dp[str]=1;
                return dp[str];
            }
        }
        dp[str]=-1;
        return dp[str];
    }


    public:
    int word_Break(string str,vector<string>&words)
    {
        unordered_map<string,int>dp;
        int ans=solve(str,words,dp);
        if(ans==1)
        return 1;
        else
        return 0;
    }
};

int main()
{
    string str="ilike";
    vector<string>words
    {"i", "like", "sam","sung", "samsung", 
    "mobile","ice","cream", "icecream",
    "man", "go", "mango"};

    ques16 q;
    cout<<q.word_Break(str,words);


    return 0;
}