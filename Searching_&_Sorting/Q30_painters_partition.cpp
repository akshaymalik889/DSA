#include<iostream>
using namespace std;


class ques30
{
    private:
    bool isPossible(int arr[],int n, int k,int mid)
    {
        int painterscount=1;
        int  blocksum=0;
    
        for(int i=0;i<n;i++)
        {
            if(blocksum + arr[i]<=mid)
            blocksum=blocksum+arr[i];
            
            else
            {
                painterscount++;
            
                if(painterscount>k || arr[i]>mid)
                {  
                    return false;
                }
            
                blocksum=arr[i];
            }
        }
        return true;
    }

    public:
    int painters_partition(int arr[],int n,int k)
    {
        int start=0;
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        int end=sum;
        int ans=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(isPossible(arr,n,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};

int main()
{
    int arr[]={5,10,30,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);

    int k=3;

    ques30 q;
    cout<<q.painters_partition(arr,n,k);

    return 0;
}