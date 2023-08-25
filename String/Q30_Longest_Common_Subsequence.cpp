#include<iostream>
#include<vector>
using namespace std;

class ques30
{
    private:

     //Approach -1 using recursion:

    int solve(string text1,string text2,int i,int j)
    {
        //base case
        if(i==text1.length() || j==text2.length())
        return 0;

        int ans=0;

        if(text1[i]==text2[j])
        ans=1+solve(text1,text2,i+1,j+1);
        else
        {
            ans=max(solve(text1,text2,i+1,j),(solve(text1,text2,i,j+1)));
        }
        return ans;
    }

    //Approach-2 using DP
    int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp)
    {
        //base case
        if(i==text1.length() || j==text2.length())
        return 0;

        //step -3 check in dp first
        if(dp[i][j] != -1)
        return dp[i][j];

        int ans=0;

        if(text1[i]==text2[j])
        ans=1+solve(text1,text2,i+1,j+1,dp);
        else
        {
            ans=max(solve(text1,text2,i+1,j,dp),(solve(text1,text2,i,j+1,dp)));
        }

        //step- 2 store in dp
        dp[i][j]=ans;

        return ans;
    }

    public:
    int Lcs(string s1,string s2)
    {
        //Approach-1 recursion
        //return solve(s1,s2,0,0);

        //Approach-2 using dp

        //create 2d vector
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return solve(s1,s2,0,0,dp); 
    }
};

int main()
{
    string s1="ABCDGH";
    string s2="AEDFHR";

    ques30 q;
    cout<<q.Lcs(s1,s2);

    return 0;
}