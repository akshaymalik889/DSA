#include<iostream>
#include<vector>
using namespace std;

class ques1
{

private:
int firstOccurence(vector<int>arr,int n,int target,int low,int high)
{
    while(low<=high)
    {
        int mid=low+(high-low/2);
        
        if(arr[mid]==target)
        {
            if(mid==0 || arr[mid-1]!=target)
            return mid;
            else
            high=mid-1;
        }
            
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return -1;
}

int lastOccurence(vector<int>arr,int n,int target,int low,int high)
{
    while(low<=high)
    {
        int mid=low+(high-low/2);
        
        if(arr[mid]==target)
        {
            if(mid==n-1 || arr[mid+1]!=target)
            return mid;
            else
            low=mid+1;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return -1;
}
    public:
    vector<int>firstLast_pos(vector<int>arr,int n,int target)
    {
        int first=firstOccurence(arr,n,target,0,n-1);
        int last=lastOccurence(arr,n,target,0,n-1);
    
        // return {first,last};
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }

};

int main()
{
    vector<int>arr{1,3,5,5,5,5,67,123,125};
    int n=arr.size();
    int target=5;

    ques1 q;
    vector<int>ans=q.firstLast_pos(arr,n,target);

    //print
    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}