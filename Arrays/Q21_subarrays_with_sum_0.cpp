#include<iostream>
#include<unordered_map>
using namespace std;

class ques21
{
    public:

    //APPROACH -1 (FINDING ALL SUBARRAYS)
    bool subarr_sum_0_ap_1(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum=sum+arr[j];

                if(sum==0)
                {
                    return true;
                }
                
            }
        }

        return false;;
    }

    //APPROACH -2 (using space)
    bool subarr_sum_0_ap_2(int arr[],int n)
    {
        //IT WORKS WHEN WE HAVE TO FIND K=0 ONLY.

        //condition-1 if there is any repeating elment in Prefix sum.
        //condition-2 if there is prefix sum =0 or k.
        //condition-3 if arr[i] is already is a 0 or k. 
        
        //for prefix sum
        int sum=0;

        //for check repeating come again
        unordered_map<int,int>m;

        for(int i=0;i<n;i++)
        {
            //prefix
            sum=sum+arr[i];
            if(arr[i]==0 || sum==0 || m.count(sum) )
            {
                return true;
            }
            else
            {
                //inserting sum in map
                m[sum]=1;
            }
        }

        return false;
    }
};

int main()
{
    int arr[]={6,3,-3,7,4};
    int n=5;

    ques21 q;
    //cout<<q.subarr_sum_0_ap_1(arr,n);
    cout<<q.subarr_sum_0_ap_2(arr,n);

    return 0;
}