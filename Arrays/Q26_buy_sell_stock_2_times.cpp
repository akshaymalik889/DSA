#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class ques26
{
    public:

    //APPROACH -1 USING DP
    int buy_sell_stock_APP_1(vector<int>arr)
    {
        int n=arr.size();

        //create dp array
        int dp[n];
        //initialize all elemetns with 0
        for(int i=0;i<n;i++)
        dp[i]=0;

        //seling price
        int maxi=arr[n-1];
        
        //cost price
        int mini=arr[0];

        //doing first transaction from right to left
        for(int i=n-2;i>=0;i--)
        {
            //here we store maximum selling price
            if(arr[i]>maxi)
            maxi=arr[i];
            
            //store profit after 1 transaction
            dp[i]=max(dp[i+1],maxi-arr[i]);
        }

        //Now doing 2nd transction from left to n
        for(int i=1;i<n;i++)
        {
            //store minimum cost price
            if(arr[i]<mini)
            mini=arr[i];
            
            //compare current profit or profit from 1 + 2nd transaction
            dp[i]=max(dp[i-1],dp[i]+(arr[i]-mini));
        }

        return dp[n-1];
    }


    //APPROACH -2 Simple loop
    int buy_sell_stock_APP_2(vector<int>arr)
    {

        int n=arr.size();

        int first_buy = INT_MIN;
        int first_sell = 0;
        int second_buy = INT_MIN;
        int second_sell = 0;
       
      for(int i=0;i<n;i++) 
      {
        //we set prices to negative, so the calculation of profit will be convenient
        first_buy = max(first_buy,-arr[i]);
        first_sell = max(first_sell,first_buy+arr[i]);
        //we can buy the second only after first is sold
        second_buy = max(second_buy,first_sell-arr[i]);
        second_sell = max(second_sell,second_buy+arr[i]);
       
    }
    
     return second_sell;
    }
    
};

int main()
{

    vector<int>arr{3,5,0,1,4};

    ques26 q;
    //cout<<q.buy_sell_stock_APP_1(arr);
    cout<<q.buy_sell_stock_APP_2(arr);

    return 0;
}