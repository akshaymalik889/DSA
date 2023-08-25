#include<iostream>
using namespace std;


class ques23
{
    public:
    int max_product(int arr[],int n)
    {
        int ans=arr[0];
        int maxi=arr[0];
        int mini=arr[0];

        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
            swap(maxi,mini);

            maxi=max(arr[i],maxi*arr[i]);
            mini=min(arr[i],mini*arr[i]);

            ans=max(maxi,ans);
        }

        return ans;
    }
};


int main()
{
    int arr[]={2,3,-2,4};
    int n=4;

    ques23 q;
    
    cout<<q.max_product(arr,n);
    
    
    return 0;
}