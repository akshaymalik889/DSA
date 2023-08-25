#include<iostream>
using namespace std;

class ques31
{
    private:
    bool solve(int cooks[],int n,int p,int mid)
    {
        int time=0;
        int paratha=0;

        for(int i=0;i<n;i++)
        {
            //find cooks
            time=cooks[i];
            int j=2;

            //finding time to take from 2nd paratha
            while(time<=mid)
            {
                paratha++;
                time=time + (cooks[i]*j);
                j++;
            }
            if(paratha>=p)
            return 1;
        }
        return 0;
    }

    public:
    int roti_parata(int cooks[],int n,int p)
    {
        int low=0;
        int high=1e8;
        
        int ans=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(solve(cooks,n,p,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};

int main()
{
    int p =10;
    int cooks[]={1,2,3,4};
    int n=sizeof(cooks)/sizeof(cooks[0]);


    ques31 q;
    cout<<q.roti_parata(cooks,n,p);

    return 0;
}