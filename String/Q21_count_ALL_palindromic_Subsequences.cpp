#include<iostream>
#include<vector>
using namespace std;

class ques21
{

    private:
    int solve(string &str,int i,int j,vector<vector<int>>&dp)
    {
        //base case
        if(i>j)
        return 0;
        
        if(i==j)
        return 1;
        
        //check in dp
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=0;
        //recursion
        if(str[i]==str[j])
        ans= solve(str,i+1,j,dp) + solve(str,i,j-1,dp) + 1;
        
        else
        ans= solve(str,i+1,j,dp) + solve(str,i,j-1,dp) - solve(str,i+1,j-1,dp);
    
        dp[i][j]=ans;
        return ans;        
    }

    public:
    int count_palindromic_sub(string str)
    {
        int n=str.length();
        
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return solve(str,0,n-1,dp);
    }
};

int main()
{
    string str="abca";

    ques21 q;
    cout<<q.count_palindromic_sub(str);

    return 0;
}