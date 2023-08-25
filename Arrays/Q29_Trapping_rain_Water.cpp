#include<iostream>
using namespace std;


class ques29
{
    void findmaxiLeft_Right(int arr[],int n,int &lmaxi,int &rmaxi,int k)
    {
        for(int i=0;i<n;i++)
        {
            if(i<k)
            lmaxi=max(lmaxi,arr[i]);
            if(i>k)
            rmaxi=max(rmaxi,arr[i]);
        }
    }
    public:

    //Approach -1 Brute Force
    int trapping_rain_1(int arr[],int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int lmaxi=0;
            int rmaxi=0;
            findmaxiLeft_Right(arr,n,lmaxi,rmaxi,i);
            int val=min(lmaxi,rmaxi)-arr[i];
            if(val>0)
            sum=sum+val;
        }
        return sum;
    }

    //Approach -2 store left max and right max use space
    int trapping_rain_2(int arr[],int n)
    {
        int left[n];
        left[0]=arr[0];
        int right[n];
        right[n-1]=arr[n-1];
        
        long ans=0;
        //left array
        for(int i=1;i<n;i++)
        {
            left[i]=max(arr[i],left[i-1]);
        }
        
        //right array
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(arr[i],right[i+1]);
        }
        
        for(int i=0;i<n;i++)
        {
            ans=ans+min(left[i],right[i])-arr[i];
        }
        return ans;
    }

    //Approach -3 without space
    int trapping_rain_3(int arr[],int n)
    {
        int low=0;
        int high=n-1;
        
        int lmaxi=0;
        int rmaxi=0;
        
        long ans=0;
        
        while(low<=high)
        {
            if(arr[low]<arr[high])
            {
                if(arr[low]>lmaxi)
                lmaxi=arr[low];
                
                else
                ans=ans+(lmaxi-arr[low]);
                
                low++;
            }
            else
            {
                if(arr[high]>rmaxi)
                rmaxi=arr[high];
                
                else
                ans=ans+(rmaxi-arr[high]);
                
                high--;
            }
        }
        return ans;
    }
};

int main()
{
    int arr[]={3,0,0,2,0,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques29 q;
    //cout<<q.trapping_rain_1(arr,n);
    //cout<<q.trapping_rain_2(arr,n);
    cout<<q.trapping_rain_3(arr,n);

    return 0;
}