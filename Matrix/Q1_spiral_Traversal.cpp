#include<iostream>
#include<vector>
using namespace std;


class ques1
{
    public:
    vector<int>spiral_Traversal(vector<vector<int>>matrix)
    {
        int r=matrix.size();
        int c=matrix[0].size();
        int top=0;
        int bottom=r-1;
        int left=0;
        int right=c-1;
        
        vector<int>ans;
        
        while(top<=bottom && left<=right)
        {
            //left to right
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            //top to bottom
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //right to left
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            //bottom to top
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;

    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };

    ques1 q;
    vector<int>ans=q.spiral_Traversal(matrix);

    //Printing spiral traversal
    for(auto i:ans)
    {
        cout<<i<<" ";
    }

    return 0;
}