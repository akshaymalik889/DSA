#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques27
{
    private:
    static bool comp(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];
    }


    public:
    int job_scheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit)
    {
        int n=startTime.size();

        //store startTime and endTime and profit in one vector
        vector<vector<int>>v(n);

        for(int i=0;i<n;i++)
        {
            int x=startTime[i];
            int y=endTime[i];
            int z=profit[i];
            v[i]={x,y,z};
        }

        //sort vector v by end time so we use comp

        sort(v.begin(),v.end(),comp);

        //create dp array
        int dp[n];

        //store profit at i=0 and profit is z ie ->2;
        dp[0]=v[0][2];

        for(int i=1;i<n;i++)
        {
            //include profit
            int incl=v[i][2];

            int last=-1;

            //apply binary search
            int low=0;
            int high=i-1;
            
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                
                //checking entime with starttime to pick next 
                if(v[mid][1]<=v[i][0])
                {
                    last=mid;
                    low=mid+1;
                }
                else
                //overlap so decrease high
                high=mid-1;
            }

            if(last!=-1)
            incl=incl + dp[last];

            int excl=dp[i-1];
            
            dp[i]=max(incl,excl);
        }
        return dp[n-1];
    }
};

int main()
{
    vector<int>startTime={1,2,3,3};
    vector<int>endTime={3,4,5,6};
    vector<int>profit={50,10,40,70};

    ques27 q;
    cout<<q.job_scheduling(startTime,endTime,profit);

    return 0;
}