#include<iostream>
#include<vector>
using namespace std;

class ques9
{
    public:

    //Approach-2 ->USING BINARY SEARCH
    int kth_smallest(vector<vector<int>>matrix,int k)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int start=matrix[0][0];
        int end=matrix[row-1][col-1];

        int mid;

        //binary search outer range
        while(start<=end)
        {
            mid=start+(end-start)/2;

            //now traverse row wise &
            // count elments which are less than mid
            int ans=0;
            for(int i=0;i<row;i++)
            {
                //inner binary search for each row
                int low=0;
                int high=col-1;
                int m;
                
                while(low<=high)
                {
                    m=low+(high-low)/2;

                    if(matrix[i][m]<=mid)
                    low=m+1;
                    else
                    high=m-1;
                }
                ans=ans+low;
            }
            if(ans<k)
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
        {1,5,9},{10,11,13},{12,13,15}
    };

    int k=8;

    ques9 q;
    cout<<q.kth_smallest(matrix,k);

    return 0;


}