#include<iostream>
#include<algorithm>
using namespace std;


class ques20
{
    public:
    void rearrange(int arr[],int n)
    {
        int k=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                swap(arr[i],arr[k]);
                k++;
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    int arr[]={1,-2,3,-5,-3,4,5,-7};
    int n=8;

    ques20 q;
    q.rearrange(arr,n);

    return 0;
}