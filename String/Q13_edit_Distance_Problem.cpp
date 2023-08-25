#include<iostream>
#include<vector>
using namespace std;

class ques13
{

    private:

    //Approach -1 Recursion
    int solve1(string word1,string word2,int i,int j)
    {
        //base case

        //(if word1 length is smaller than word2 length)
        if(i==word1.length())
        return word2.length()-j;

        //(if word2 length is smaller than word1 length)
        if(j==word2.length())
        return word1.length()-i;

        int ans=0;

        //if word matches 
        if(word1[i]==word2[j])
        return solve1(word1,word2,i+1,j+1);

        else
        {
            //insert
            int insertAns= 1 + solve1(word1,word2,i,j+1);

            //delete
            int deleteAns= 1 + solve1(word1,word2,i+1,j);

            //replace
            int replaceAns= 1 + solve1(word1,word2,i+1,j+1);

            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }

    //Approach -2 DP + MEMOIZATION
    int solve2(string word1,string word2,int i,int j,vector<vector<int>>&dp)
    {
        //base case

        //(if word1 length is smaller than word2 length)
        if(i==word1.length())
        return word2.length()-j;

        //(if word2 length is smaller than word1 length)
        if(j==word2.length())
        return word1.length()-i;

        // step 3 -> check in dp first
        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans=0;

        //if word matches 
        if(word1[i]==word2[j])
        return solve2(word1,word2,i+1,j+1,dp);

        else
        {
            //insert
            int insertAns= 1 + solve2(word1,word2,i,j+1,dp);

            //delete
            int deleteAns= 1 + solve2(word1,word2,i+1,j,dp);

            //replace
            int replaceAns= 1 + solve2(word1,word2,i+1,j+1,dp);

            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        //step -2 store in dp
        dp[i][j]=ans;
        return ans;
    }

    public:

    //Approach-1 Recursion
    int edit_Distance_App_1(string word1,string word2)
    {
        return solve1(word1,word2,0,0);
    }
    
    //Approach-2 Dp + Memoization
    int edit_Distance_App_2(string word1,string word2)
    {
        //Step -1 create dp array
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));

        return solve2(word1,word2,0,0,dp);
    }
};


int main()
{
    string word1="horse";
    string word2="ros";

    ques13 q;
    //cout<<q.edit_Distance_App_1(word1,word2);
    cout<<q.edit_Distance_App_2(word1,word2);

    return 0;
}