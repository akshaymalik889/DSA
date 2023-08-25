#include<iostream>
using namespace std;

class ques33
{
    public:

    //Approach-2
    int minimum_swaps(int arr[],int n, int k)
    {
        //count good numbers
        int good=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            good++;
        }

        //count bad numbers upto count of good numbers
        int bad=0;
        for(int i=0;i<good;i++)
        {
            if(arr[i]>k)
            bad++;
        }

        //traverse array with window of good size
        int ans=bad;
        for(int i=0,j=good;j<n;)
        {
            if(arr[j]>k)
            bad++;
            if(arr[i]>k)
            bad--;

            ans=min(ans,bad);
            i++;
            j++;
        }
        return ans;
    }
};

int main()
{

    int arr[]={2,7,9,5,8,7,4};
    int n=7;
    int k=6;

    ques33 q;
    cout<<q.minimum_swaps(arr,n,k);
}