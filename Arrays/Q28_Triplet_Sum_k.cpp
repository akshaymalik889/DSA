#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;


class ques28
{
    public:
    
    //Approach-1 (Hashing)

    int triplet_sum_App_1(int arr[],int n,int x)
    {
        

        for(int i=0;i<n-1;i++)
        {
            unordered_map<int,int>m;
            for(int j=i+1;j<n;j++)
            {
                int val=x-(arr[i]+arr[j]);
                if(m.count(val))
                return 1;
                else
                m[arr[j]]=1;
            }
        }
        return 0;
    }

    //Approach-2 (Sorting + two pointer)

    int triplet_sum_App_2(int arr[],int n,int x)
    {

        //sort the array
        sort(arr,arr+n);

        for(int i=0;i<n-2;i++)
        {
            //two pointer
            int l=i+1;
            int r=n-1;
            
            while(l<r)
            {
                int sum=arr[i]+arr[l]+arr[r];
                if(sum==x)
                return 1;
                else if(sum<x)
                l++;
                else
                r--;
            }
        }
        return 0;
    }

};


int main()
{

    int arr[]={1,4,45,6,10,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=13;

    ques28 q;
    //cout<<q.triplet_sum_App_1(arr,n,x);
    cout<<q.triplet_sum_App_2(arr,n,x);

    return 0;

}