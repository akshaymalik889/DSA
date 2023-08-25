#include<iostream>
using namespace std;

class ques8
{
    public:
    int majority_element(int arr[],int n)
    {
        int count=1;
        int maj=arr[0];
        
        //finding majority element
        for(int i=1;i<n;i++)
        {
            if(arr[i]==maj)
            count++;
            
            else
            count--;
            
            if(count==0)
            {
                maj=arr[i];
                count=1;
            }
        }
        
        //checking count of majority element now
        count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==maj)
            count++;
        }
        
        if(count>n/2)
        return maj;
        
        else
        return -1;
    }
};

int main()
{
    int arr[]={3,1,3,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques8 q;
    cout<<q.majority_element(arr,n);


    return 0;
}