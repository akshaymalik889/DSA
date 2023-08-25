#include<iostream>
#include<unordered_map>
using namespace std;

class ques15
{
    public:
    
    //Approach-1 brute force ->finding all subarrays
    int print_subarray_Ap_1(int arr[],int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum=sum+arr[j];
                
                if(sum==0)
                count++;
            }
        }
        return count;
    }

     //Approach-2 Hashing
    int print_subarray_Ap_2(int arr[],int n)
    {
        unordered_map<int,int>m;
        int count=0;
        int sum=0;
        m[sum]++;
        
        for(int i=0;i<n;i++)
        {
            //prefix
            sum=sum+arr[i];
            
            if(m.count(sum))
            count=count+m[sum];
            
            m[sum]++;
        }
        return count;
    }
};

int main()
{
    int arr[]={0,0,5,5,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques15 q;
    //cout<<q.print_subarray_Ap_1(arr,n);
    cout<<q.print_subarray_Ap_2(arr,n);
    
    return 0;
}