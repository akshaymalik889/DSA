#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;


class ques32
{
    public:
    vector<vector<int>>nearest_1(vector<vector<int>>grid)
    {
        int n=grid.size();
        int m=grid[0].size();
    
        //make a 2d vector and store INT_MAX in all places
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
    
        queue<pair<int,int>>q;
    
        //make all 1 to 0 and store in queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
    
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            
            //up
            if((i-1)>=0 && ans[i][j]+1 < ans[i-1][j])
            {
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
            
            //left
            if((j-1)>=0 && ans[i][j]+1 < ans[i][j-1])
            {
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
            
            //down
            if((i+1)<n && ans[i][j]+1 < ans[i+1][j])
            {
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
            
            //right
            if((j+1)<m && ans[i][j]+1 < ans[i][j+1])
            {
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            
            q.pop();
        }
        return ans;

    }
};

int main()
{
    vector<vector<int>>grid{{1,0,1},{1,1,0},{1,0,0}};

    ques32 q;
    vector<vector<int>>ans=q.nearest_1(grid);

    //print
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}