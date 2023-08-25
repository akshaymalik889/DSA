#include<iostream>
using namespace std;

class ques32
{
    public:

    //Approach-2 ->dutch flag
    void partioning(int arr[],int n,int a,int b)
    {
        int low=0;
        int high=n-1;
        int i=0;

        //partioning
        while(i<=high)
        {
            if(arr[i]<a)
            {
                swap(arr[i],arr[low]);
                i++;
                low++;
            }
            else if(arr[i]>=a && arr[i]<=b)
            i++;

            else
            {
                swap(arr[i],arr[high]);
                high--;
            }
        }

        //print array
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" "; 
    }
};

int main()
{
    int arr[]={6,3,2,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=3,b=4;

    ques32 q;
    q.partioning(arr,n,a,b);


    return 0;
}