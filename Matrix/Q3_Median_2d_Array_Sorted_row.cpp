#include<iostream>
#include<vector>
using namespace std;


class ques3
{
    public:
    //Approach -2 ->BINARY SEARCH
    int median_2D_App_2(vector<vector<int>>matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0,end=2000;
        int n=row*col;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            //now iterate row wise to check
            ///total values who are less than mid
            int ans=0;
            for(int i=0;i<row;i++)
            {
                //we again use binary search to find
                int low=0,high=col-1;
                while(low<=high)
                {
                    int m=low+(high-low)/2;
                    if(matrix[i][m]<=mid)
                    low=m+1;
                    else
                    high=m-1;
                }
                ans=ans+low;
            }
            if(ans<=n/2)
            start=mid+1;
            else
            end=mid-1;
            
        }
        return start;
    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {1,3,5},{2,6,9},{3,6,9}
    };

    ques3 q;
    cout<<q.median_2D_App_2(matrix);


}