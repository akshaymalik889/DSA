#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques14
{
    public:
    vector<int>next_Permutation(vector<int>arr,int n)
    {
        //first find from last index arr[i]>arr[i-1]
        
        int index=-1;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                index=i;
                break;
            }
        }
        
        //if index not change means already we have last permutation
        //so we just reverse
        if(index==-1)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        int prev=index;
        
        for(int i=index+1;i<n;i++)
        {
            if(arr[i]>arr[index-1] && arr[i]<=arr[prev])
            prev=i;
        }
        
        //swap now
        swap(arr[index-1],arr[prev]);
        
        //now reverse from index to end of array
        reverse(arr.begin()+index,arr.end());
        return arr;
    }
};

int main()
{
    vector<int>arr{1,2,3,6,5,4};
    int n=arr.size();

    ques14 q;
    vector<int>ans=q.next_Permutation(arr,n);

    //print
    for(auto i:ans)
    cout<<i<<" ";

    return 0;

}