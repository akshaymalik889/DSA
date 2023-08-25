#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class ques10
{
    private:
    int binarySearch(int arr[],int start,int end,int y)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(arr[mid]==y)
            return mid;
            
            else if(arr[mid]>y)
            end=mid-1;

            else
            start=mid+1;
        }
        return -1;
    }

    public:

    //Approach-2 USING MAP
    bool find_Pair_App_2(int arr[],int n,int x)
    {
        unordered_map<int,int>m;

        for(int i=0;i<n;i++)
        {
            m[arr[i]]=1;
        }

        for(int i=0;i<n;i++)
        {
            int diff=arr[i]+x;

            if(m.count(diff))
            return true;
        }
        return false;
    }

     //Approach-3 SORT + BINARY SEARCH
    bool find_Pair_App_3(int arr[],int n,int x)
    {
        sort(arr,arr+n);

        for(int i=0;i<n;i++)
        {
            int y=arr[i]+x;

            int index=binarySearch(arr,i+1,n-1,y);
            if(index!=-1)
            return true;
        }
        return false;
    }
};

int main()
{
    int arr[]={5,20,3,2,5,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=78;

    ques10 q;
    //cout<<q.find_Pair_App_2(arr,n,x);
    cout<<q.find_Pair_App_3(arr,n,x);

    return 0;
}