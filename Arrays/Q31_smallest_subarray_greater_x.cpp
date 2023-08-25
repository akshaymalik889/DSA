#include<iostream>
#include<limits.h>
using namespace std;


class ques31
{
    public:

    //Approach-1 brute force->finding all subarrays
    int smallest_subarray_App_1(int arr[],int n,int x)
    {
        int mini=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum=sum+arr[j];
                if(sum>x)
                {
                    mini=min(mini,j-i+1);
                }
            }
        }
        return mini;
    }

    //Approach-2 
    int smallest_subarray_App_2(int arr[],int n,int x)
    {
        int sum=0;
        int mini=INT_MAX;

        for(int i=0,j=0;i<n && j<=n;)
        {
            if(sum<=x)
            {
                if(j<n)
                sum=sum+arr[j];
                else
                sum=sum;
                
                j++;
            }
            else
            {
                mini=min(mini,j-i);
                sum=sum-arr[i];
                i++;
            }
        }
        return mini;

    }
};

int main()
{
    int arr[]={1,4,45,6,0,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=51;

    ques31 q;
    //cout<<q.smallest_subarray_App_1(arr,n,x);
    cout<<q.smallest_subarray_App_2(arr,n,x);

}