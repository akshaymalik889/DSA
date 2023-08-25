#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class ques21_1
{

    private:
    
    //Approach-2
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
            ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }

        //step- 2 store in dp
        dp[i][j]=ans;

        return ans;
    }

    public:

    //Approach-2 using DP
    int longest_palindrome_sub(string str)
    {
       

        //find longest commom subsequence of:
        //given string && reverse of given string.

        //reverse string 
        string str2=str;
        reverse(str2.begin(),str2.end());
        
        //create 2d vector
        vector<vector<int>>dp(str.length(),vector<int>(str2.length(),-1));
    
        return solve(str,str2,0,0,dp);
    }
};

int main()
{
    string str="bbbab";

    ques21_1 q;
    cout<<q.longest_palindrome_sub(str);

    return 0;
}