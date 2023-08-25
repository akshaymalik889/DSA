#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques18
{
    public:
    int min_swaps(vector<int>nums)
    {
        int n=nums.size();
	    vector<pair<int,int>>v(n);
	    
	    //store value with its index in vector
	    for(int i=0;i<n;i++)
	    {
	        v[i]=make_pair(nums[i],i);
	    }
	    
	    //now sort the new vector
	    sort(v.begin(),v.end());
	    
	    int count=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i)
	        continue;
	        
	        else
	        {
	            count++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return count;
    }
};


int main()
{
    vector<int>nums={1,5,4,3,2};

    ques18 q;
    cout<<q.min_swaps(nums);

    return 0;
}