#include<iostream>
#include<vector>
using namespace std;

class ques8_0
{

private:

    //Approach -1 using recursion:
    int solve1(string str1,string str2,int i,int j)
    {
        //base case
        if(i==str1.length() || j==str2.length())
        return 0;

        int ans=0;

        if(str1[i]==str2[j])
        ans=1+solve1(str1,str2,i+1,j+1);
        else
        {
            ans=max(solve1(str1,str2,i+1,j),(solve1(str1,str2,i,j+1)));
        }
        return ans;
    }

    //Approach -2 using Dp:
    int solve2(string &str1,string &str2,int i,int j,vector<vector<int>>&dp)
    {
        //base case
        if(i==str1.length() || j==str2.length())
        return 0;

        //step -3 check in dp first
        if(dp[i][j] != -1)
        return dp[i][j];

        int ans=0;

        if(str1[i]==str2[j])
        ans=1+solve2(str1,str2,i+1,j+1,dp);
        else
        {
            ans=max(solve2(str1,str2,i+1,j,dp),solve2(str1,str2,i,j+1,dp));
        }

        //step- 2 store in dp
        dp[i][j]=ans;

        return ans;
    }

public:

    //Approach-1 Recursion
    int longest_common_sub_App1(string str1,string str2)
    {
        return solve1(str1,str2,0,0);
    }
    
    //Approach-2 DP
    int longest_common_sub_App2(string str1,string str2)
    {
        //create 2d vector
        vector<vector<int>>dp(str1.length(),vector<int>(str2.length(),-1));
        return solve2(str1,str2,0,0,dp);
    }
};

int main()
{
    string str1="abcde";
    string str2="ace";

    ques8_0 q;

    //Approach-1 recursion
  // cout<<q.longest_common_sub_App1(str1,str2);


    //Approach-2 using dp
    cout<<q.longest_common_sub_App2(str1,str2);


    return 0;
}