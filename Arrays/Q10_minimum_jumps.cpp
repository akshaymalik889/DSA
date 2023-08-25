#include<iostream>
using namespace std;

class ques10
{
    public:
    
    //Approach -1 ->Dynamic Programming (DP)
    int minimum_jumps_app_1(int arr[],int n)
    {
        //dp array to store minimum jumps from starting point to ith position
        int dp[n];

        //initialize dp array with INT_MAX
        for(int i=0;i<n;i++)
        {
            dp[i]=INT_MAX;
        }
        //bcoz to reach 0 we no need to do any jump
        dp[0]=0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                //here we find can we reach to that position or not
                if(dp[j]!=INT_MAX && arr[j]+j>=i)
                {
                    //here we update the dp[i],if this new jump is less than existing jumps to reach ith position
                    if(dp[j]+1<dp[i])
                    dp[i]=dp[j]+1; 
                }
            }
        }
        //it means we reach last position and find ans
        if(dp[n-1]!=INT_MAX)
        return dp[n-1];
        else
        return -1;

    }

     int minimum_jumps_app_2(int arr[],int n)
    {
        int maxR=arr[0];
        int step=arr[0];
        int jump=1;

        //if only 1 element
        if(n==1)
        return 0;

        //if starting point is zero so we cant move
        else if(arr[0]==0)
        return -1;

        else
        {
            for(int i=1;i<n;i++)
            {
                if(i==n-1)
                return jump;
                
                maxR=max(maxR,i+arr[i]);
                step--;

                if(step==0)
                {
                    jump++;
                if(i>=maxR)
                {
                    return -1;
                }
                step=maxR-i;
                }
            }
        }
        return jump;

    }
};

int main()
{
    int arr[]={1,4,3,2,6,7};
    int n=6;

    ques10 q;
    
    //Approach-1 ->DP o(n2)
   // cout<<q.minimum_jumps_app_1(arr,n);

    //Approach-2 ->o(n)
    cout<<q.minimum_jumps_app_2(arr,n);

    return 0;
}