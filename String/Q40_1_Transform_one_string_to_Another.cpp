#include<iostream>
#include<vector>
using namespace std;


//Ques ; transform one string to another by doing 
//       insertion or deletion at anywhere

class ques40
{
    private:

    int solve(string str1,string str2,int i,int j,vector<vector<int>>&dp)
    {
        //base case
        if(i==str1.length() || j==str2.length())
        return 0;

        //check in dp first
        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans=0;

        //Recursive calls
        if(str1[i]==str2[j])
        ans=1 + solve(str1,str2,i+1,j+1,dp);

        else
        ans=  max(solve(str1,str2,i+1,j,dp),solve(str1,str2,i,j+1,dp));

        //store in dp
        dp[i][j]=ans;
        
        return ans;
    }

    int lcs(string str1,string str2)
    {
        vector<vector<int>>dp(str1.length(),vector<int>(str2.length(),-1));
        return solve(str1,str2,0,0,dp);
    }

    public:
    int min_operations_convert(string str1,string str2)
    {
        int length_Lcs=lcs(str1,str2);

        return str1.length() + str2.length() - (2*length_Lcs); 
    }
};


int main()
{
    string str1="EACBD";
    string str2="EABCD";

    ques40 q;
    cout<<q.min_operations_convert(str1,str2);


    return 0;
}