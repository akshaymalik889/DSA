#include<iostream>
#include<algorithm>
using namespace std;

class ques13
{
    public:
    int triplet_Sum(int arr[],int n,int x)
    {
        int count=0;

        sort(arr,arr+n);

        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1,k=n-1;j<k;)
            {
                int sum=arr[i]+arr[j]+arr[k];
                
                if(sum<x)
                {
                    int index=k-j;
                    count=count+index;
                    j++;
                }
                else
                k--;
            }
        }
        return count;
    }
};

int main()
{
    int arr[]={5,1,3,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=12;

    ques13 q;
    cout<<q.triplet_Sum(arr,n,x);

    return 0;
}