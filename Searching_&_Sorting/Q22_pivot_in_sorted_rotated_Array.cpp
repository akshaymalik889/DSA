#include<iostream>
using namespace std;


class ques22
{
    public:

    //Approach-1 
    int find_pivot_App_1(int arr[],int n)
    {
        int pivot=arr[0];

        for(int i=1;i<n;i++)
        {
            if(arr[i]<pivot)
            {
                pivot=arr[i];
                break;
            }
        }
        return pivot;
    }

    //Approach-2 ->BINARY SEARCH
    int find_pivot_App_2(int arr[],int n)
    {
        int low=0;
        int high=n-1;

        while(low<high)
        {
            int mid=low+(high-low)/2;

            //means value increasing in mid to high
            if(arr[mid]<arr[high])
            high=mid;

            else if(arr[mid]>arr[high])
            low=mid+1;
        }
        return arr[low];
    }
};

int main()
{
    int arr[]={30,40,50,10,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques22 q;

    //Approach-1
    //cout<<q.find_pivot_App_1(arr,n);

    //Approach-2
   cout<<q.find_pivot_App_2(arr,n);

    return 0;
}