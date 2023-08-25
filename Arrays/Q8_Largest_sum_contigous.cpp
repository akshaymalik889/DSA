#include<iostream>
#include<limits.h>
using namespace std;


class ques8
{
    public:
    //Approach-1 -> BRUTE Force
    void subarray_sum_approach_1(int arr[],int n)
    {
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum=sum+arr[k];
                }
                maxi=max(sum,maxi);
            }
        }

        cout<<"max subarray sum is:"<<maxi<<endl;
    }

    //Approach-2 -> Use prefix sun
     void subarray_sum_approach_2(int arr[],int n)
    {
        int maxi=INT_MIN;
        int pre[n];
        pre[0]=arr[0];

        //store prefix sum
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+arr[i];
        }

        //finding largest sum contiguous subarray
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i-1>=0)
                {
                    int sum=pre[j] - pre[i-1];
                    maxi=max(sum,maxi);
                }
                
                else
                {
                    int sum=pre[j];
                    maxi=max(sum,maxi);
                }
                

                
            }
        }

        cout<<"max subarray sum is:"<<maxi<<endl;
    }

    //Approach-3 -> Use Kadane Algorithm
    void subarray_sum_approach_3(int arr[],int n)
    {
        int maxi=INT_MIN;

        int cursum=0;

        for(int i=0;i<n;i++)
        {
            cursum=cursum+arr[i];
            maxi=max(cursum,maxi);

            if(cursum<0)
            cursum=0;
        }

        cout<<"max subarray sum is:"<<maxi<<endl;
    }
};

int main()
{
    int arr[]={7,5,-13,5,10,-2,5};
    int n=7;
    
    ques8 q;
    //q.subarray_sum_approach_1(arr,n);
    q.subarray_sum_approach_2(arr,n);
    //q.subarray_sum_approach_3(arr,n);


    return 0;
}