#include<iostream>
using namespace std;

class ques36
{
    public:
    //Approach-1 ->THREE WAY PARTIONING
    void sort_0_1_2_Approach_1(int * arr,int n)
    {
        int c0=0,c1=0,c2=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            c0++;
            else if(arr[i]==1)
            c1++;
            else
            c2++;
        }

        for(int i=0;i<n;i++)
        {
            if(c0>0)
            {
                arr[i]=0;
                c0--;
            }
            else if(c1>0)
            {
                arr[i]=1;
                c1--;
            }
            else
            {
                arr[i]=2;
                c2--;
            }
        }

        //sort array is
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" "; 
        }
    }

    //Approach 2 -> Dutch National Flag
    void sort_0_1_2_Approach_2(int arr[],int n)
    {

        int low=0,high=n-1;

        int i=0;
        while(i<=high)
        {
            if(arr[i]==0)
            {
                swap(arr[i],arr[low]);
                low++;
                i++;
            }
            else if(arr[i]==1)
            {
                i++;
            }
            else if(arr[i]==2)
            {
                swap(arr[i],arr[high]);
                high--;
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
    int arr[]={0,1,0,0,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques36 q;
    
    //q.sort_0_1_2_Approach_1(arr,n);
    q.sort_0_1_2_Approach_2(arr,n);

    
}