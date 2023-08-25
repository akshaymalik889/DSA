#include<iostream>
#include<vector>
using namespace std;

class ques16
{
    public:
    //Approach-1 ->Brute force
    vector<long long int>Array_Puzzle_App1(vector<long long int>nums,int n)
    {
        vector<long long int>ans(n);
        
        for(int i=0;i<n;i++)
        {
            long long int product=1;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                product=product * nums[j];
            }
            ans[i]=product;
        }
        return ans;
    }

    //Approach 3 ->prefix and suffix

    vector<long long int>Array_Puzzle_App2(vector<long long int>nums,int n)
    {
        vector<long long int>left(n);
        vector<long long int>right(n);
       
        left[0]=1;
        right[n-1]=1;
       
        //prefix
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
       
        //suffix
            for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
       
        //store in vector itself left[i]* right[i] 
        for(int i=0;i<n;i++)
        {
            nums[i]=left[i] * right[i];
        }
        return nums;
    }
};


int main()
{
    vector<long long int>nums{10,3,5,6,2};
    int n=nums.size();

    ques16 q;
    //vector<long long int>ans=q.Array_Puzzle_App1(nums,n);
    vector<long long int>ans=q.Array_Puzzle_App2(nums,n);

    //print
    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}