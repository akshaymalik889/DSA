#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class ques31
{
    public:
    int Rotten_Oranges(vector<vector<int>>&grid)
    {
        queue<pair<int,int> >q;
        
        int row=grid.size();
        int col=grid[0].size();
        
        //store all rotten index in queue
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
            }
        }
        
        int count=0;
        //add partition
        q.push({-1,-1});
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            
            //it means only -1,-1 left no rotten(2) elment left
            //so we get our answer
            if(i==-1 && j==-1 && q.size()==1)
            {
                q.pop();
                break;
            }
            //it means now we reach -1,-1 and still more indexes of 2 left
            else if(i==-1 && j==-1 && q.size()>1)
            {
               count++;
               q.pop();
               q.push({-1,-1});
            }
            else
            {
                //rotting up
                if( (i-1)>=0 && grid[i-1][j]==1 )
                {
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                
                //rotting left
                if( (j-1)>=0 && grid[i][j-1]==1 )
                {
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                //rotting down
                if( (i+1)<row && grid[i+1][j]==1 )
                {
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                //rotting right
                if( (j+1)<col && grid[i][j+1]==1 )
                {
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                
                q.pop();
            }
        }
        
        //checking any 1 left or not
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        
        //no 1 left 
        return count;
    }
};


int main()
{
    vector<vector<int>>grid={ {1,1,2},{0,1,2},{2,1,1} };

    ques31 obj;
    cout<<obj.Rotten_Oranges(grid);

    return 0;
}