#include<iostream>
#include<vector>

using namespace std;

class dp
{
    private:

//METHOD-1
    int Method_1(vector<int>&nums,int i)
    {
        //base case
        if(i<0)
        return 0;

        if(i==0)
        return nums[0];

        int incl=Method_1(nums,i-2) + nums[i];
        int excl=Method_1(nums,i-1) + 0;

        return max(incl,excl);
    } 

//Mehtod-2
    int Method_2(vector<int>&nums,vector<int>&dp,int i)
    {
        //base case
        if(i<0)
        return 0;

        if(i==0)
        return nums[0];

        //step -3
        if(dp[i]!=-1)
        return dp[i];

        int incl=Method_2(nums,dp,i-2) + nums[i];
        int excl=Method_2(nums,dp,i-1) + 0;

        //step -2
        dp[i]=max(incl,excl);

        return dp[i];
    }

//METHOD-3
    int Method_3(vector<int>&nums)
    {
        //step-1
        int n=nums.size();
        vector<int>dp(n,0);

        //step-2
        dp[0]=nums[0];

        //step 3
        for(int i=1;i<n;i++)
        {
            int incl=dp[i-2]+nums[i];
            int excl=dp[i-1]+0;
            dp[i]=max(incl,excl);
        }

        return dp[n-1];
    }

//METHOD -4
    int Method_4(vector<int>&nums)
    {
        int n=nums.size();
        
        int prev2=0;
        int prev1=nums[0];

        for(int i=1;i<n;i++)
        {
            int incl=prev2+nums[i];
            int excl=prev1+0;

            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }

    public:
    void max_sum(vector<int>&nums)
    {
        int n=nums.size();

    //we start  i from last

        //METHOD -1 RECURSION
        // int i=n-1;
        // int ans= Method_1(nums,i);
        // cout<<ans;

        //METHOD -2 RECURSION + MEMOIZATION
        // int i=n-1;
        // vector<int>dp(n,-1);
        // int ans=Method_2(nums,dp,i);
        // cout<<ans;

        //METHOD -3 TABULATION
        // int ans= Method_3(nums);
        // cout<<ans;

        //METHOD-4 SPACE OPTIMIZATION
        int ans=Method_4(nums);
        cout<<ans;

    }
};


int main()
{
    dp d;

    vector<int>arr{5,5,10,100,10,5};
    d.max_sum(arr);
}