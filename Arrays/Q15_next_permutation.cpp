#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques15
{
    public:
    void next_permutation(vector<int>&nums)
    {
        int index=-1;
        
        int n=nums.size();
        
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                index=i;
                break;
            }
        }
        
        //means array is in desending order ie already it is last permutation
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
    
        int prev=index;
        
        for(int i=index+1;i<n;i++)
        {
            if(nums[i]>nums[index-1] && nums[i]<=nums[prev])
                prev=i;
        }
        
        //swap now
        swap(nums[index-1],nums[prev]);
        
        //now reverse from index to end of array
        reverse(nums.begin()+index,nums.end());
        return ;
       
    }
};

int main()
{
    vector<int>nums{1,5,8,4,7,6,5,3,1};

    ques15 q;
    q.next_permutation(nums);

    for(auto i:nums)
    {
        cout<<i<<" ";
    }

    return 0;

}