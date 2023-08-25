#include<iostream>
#include<vector>
using namespace std;


class ques38
{
    private:

    //Approach-1 ->Recursion
    bool solve1(string &str,string &pattern,int i,int j)
    {
        //base case

        //string and pattern full traverse
        if(i<0 && j<0)
        return true;

        //string not fully traverse but pattern fully traversed
        if(i>=0 && j<0)
        return false;

        //string completed but pattern still left
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(pattern[k]!='*')
                return false;
            }
            return true;
        }

        //Recursive calls

        //Match
        if(str[i]==pattern[j] || pattern[j]=='?')
        return solve1(str,pattern,i-1,j-1);

        //star in pattern
        else if(pattern[j]=='*')
        {
            return (solve1(str,pattern,i-1,j) || solve1(str,pattern,i,j-1));
        }

        //NOT Match
        else
        return false;
    }

    //Approach-2 ->Dp + MEMOIZATION
    bool solve2(string &str,string &pattern,int i,int j,vector<vector<int>>&dp)
    {
        //base case

        //string and pattern full traverse
        if(i<0 && j<0)
        return true;

        //string not fully traverse but pattern fully traversed
        if(i>=0 && j<0)
        return false;

        //string completed but pattern still left
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(pattern[k]!='*')
                return false;
            }
            return true;
        }

        // step -3 check in dp
        if(dp[i][j]!=-1)
        return dp[i][j];

        //Recursive calls

        //Match
        if(str[i]==pattern[j] || pattern[j]=='?')
        {
            //store in dp
            dp[i][j]=solve2(str,pattern,i-1,j-1,dp);
            return dp[i][j];
        }

        //star in pattern
        else if(pattern[j]=='*')
        {
            //store in dp
            dp[i][j]=solve2(str,pattern,i-1,j,dp) || solve2(str,pattern,i,j-1,dp);
            return dp[i][j];
        }

        //NOT Match
        else
        return false;
    }

    public:
    //Approach-1 -> Recursion
    bool wildcard_Matching_App_1(string str,string pattern)
    {
        return solve1(str,pattern,str.length()-1,pattern.length()-1);
    }

    //Approach-2 -> Dp + Memoization
    bool wildcard_Matching_App_2(string str,string pattern)
    {
        vector<vector<int>>dp(str.length(),vector<int>(pattern.length(),-1));
        return solve2(str,pattern,str.length()-1,pattern.length()-1,dp);
    }
};


int main()
{
    string str="abcde";
    string pattern="a*c?e";

    ques38 q;

    //Approach-1 -> Recursion
    //cout<<q.wildcard_Matching_App_1(str,pattern);

    //Approach-2 -> Dp + Memoization
    cout<<q.wildcard_Matching_App_2(str,pattern);





    return 0;
}