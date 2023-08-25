#include<iostream>
#include<algorithm>
using namespace std;


class ques26
{
    private:
    bool solve(int arr[],int n,int k,int mid)
    {
        int sum=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            sum=sum+arr[i]-mid;
        }

        if(sum>=k)
        return true;
        
        else
        return false;
    }


    public:
    int ekospoj(int arr[],int n,int k)
    {
        int low=0;
        int ans=0;

        //inbuilt function to get max element
        int high=*max_element(arr,arr+n);

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(solve(arr,n,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};

int main()
{
    int arr[]={20,15,10,17};
    int n=sizeof(arr)/sizeof(arr[0]);

    int k=7;

    ques26 q;
   cout<< q.ekospoj(arr,n,k);

   return 0;
}