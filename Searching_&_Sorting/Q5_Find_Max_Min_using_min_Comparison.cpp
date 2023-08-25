#include<iostream>
#include<limits.h>
using namespace std;


class ques5
{
    public:
    void min_max(int arr[],int n)
    {
        int maxi;
        int mini;
        int i;

        if(n%2==0)
        {
            if(arr[0]>arr[1])
            {
                maxi=arr[0];
                mini=arr[1];
            }
            else
            {
                maxi=arr[1];
                mini=arr[0];
            }
            i=2;
        }
        else
        {
            maxi=arr[0];
            mini=arr[0];
            i=1;
        }

        while(i<n-1)
        {
            if(arr[i]>arr[i+1])
            {
                if(arr[i]>maxi)
                maxi=arr[i];

                if(arr[i+1]<mini)
                mini=arr[i+1];
            }

            else
            {
                if(arr[i+1]>maxi)
                maxi=arr[i+1];

                if(arr[i]<mini)
                mini=arr[i];
            }
            i=i+2;
        }
        cout<<"maximum="<<maxi<<endl;
        cout<<"minimum="<<mini<<endl;
    }
};

int main()
{
    int arr[]={2,5,1,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques5 q;
    q.min_max(arr,n);
    
    return 0;
}