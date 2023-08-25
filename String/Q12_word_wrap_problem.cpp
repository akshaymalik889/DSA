#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class ques12
{
    public:
    int word_wrap(vector<int>nums,int k)
    {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        int i,j;
        int curr,cost;
        dp[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            curr=-1;
            for(j=i;j<n;j++)
            {
                curr+=nums[j]+1;
                if(curr>k)
                {
                    break;
                }
                if(j==n-1)
                {
                    cost=0;
                }
                else
                {
                    cost=(k-curr)*(k-curr)+dp[j+1];
                }
                dp[i]=min(dp[i],cost);
            }
        }
        return dp[0];
    }
};

int main()
{
    vector<int>nums
    {
      3,2,2,5  
    };
    int k=6;

    ques12 q;
    cout<<q.word_wrap(nums,k);

}