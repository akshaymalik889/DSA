#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class ques4_5
{
    public:
    vector<int> Kth_largest(int arr[],int n,int k)
    {
        priority_queue<int,vector<int>,greater<int>>pq;
	  
	    for(int i=0;i<k;i++)
	    {
	        pq.push(arr[i]);
	    }
	    
        int i=k;
	  
        while(i<n)
	    {
	        if(arr[i]>pq.top())
	        {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	        i++;
	    }
	  
	    vector<int>ans(k);
	    
        while(!pq.empty())
	    {
	        ans[k-1]=pq.top();
	        pq.pop();
	        k--;
	    }
	    return ans;
    }
};

int main()
{
    int arr[]={12, 5, 787, 1, 23};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;

    ques4_5 q;
    vector<int>ans=q.Kth_largest(arr,n,k);

    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}