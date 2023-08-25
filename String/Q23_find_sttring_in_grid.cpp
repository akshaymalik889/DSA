#include<iostream>
#include<vector>
using namespace std;


class ques23
{

    private:

    bool left(vector<vector<char>>&grid, string word, int i,int j)
    {
        for(int x=0;x<word.length();x++)
        {
            if(j < 0 || grid[i][j]!=word[x]) 
            return false;
            
            j--;
        }
        return true;
    }
    
    bool right(vector<vector<char>>&grid, string word, int i,int j)
    {
        int n=grid[i].size();
        for(int x=0;x<word.length();x++)
        {
            if(j >=n || grid[i][j]!=word[x]) 
            return false;
            
            j++;
        }
        return true;
    }
    
    bool up (vector<vector<char>>&grid, string word, int i,int j)
    {
        for(int x=0;x<word.length();x++)
        {
            if(i < 0 || grid[i][j]!=word[x]) 
            return false;
        
            i--;
        }
        return true;
    }
    
    
    bool down(vector<vector<char>>&grid, string word, int i,int j)
    {
        int n=grid.size();
        for(int x=0;x<word.length();x++)
        {
            if(i >=n || grid[i][j]!=word[x]) 
            return false;
            
            i++;
        }
        return true;
    }


    bool leftUp(vector<vector<char>>&grid, string word, int i,int j)
    {
        for(int x=0;x<word.length();x++)
        {
        
            if( i<0 || j < 0 || grid[i][j]!=word[x]) 
            return false;
            
            j--;
            i--;
        }
        return true;
    }
    
    
    bool leftDown(vector<vector<char>>&grid, string word, int i,int j)
    {
        int n=grid.size();
        for(int x=0;x<word.length();x++)
        {
            if( i>=n || j < 0 || grid[i][j]!=word[x]) 
            return false;
        
            j--;
            i++;
        }
        return true;
    }
    
    
    bool rightUp(vector<vector<char>>&grid, string word, int i,int j)
    {
        int n=grid[i].size();
        for(int x=0;x<word.length();x++)
        {
            if( i<0 || j >=n || grid[i][j]!=word[x]) 
            return false;
            
            j++;
            i--;
        }
        return true;
    }
 
 
    bool rightDown (vector<vector<char>>&grid, string word, int i,int j)
    {
        int m=grid.size();
        int n=grid[i].size();
        for(int x=0;x<word.length();x++)
        {
            if( i>=m || j >=n || grid[i][j]!=word[x]) 
            return false;
            
            j++;
            i++;
        }
        return true;
    }

    public:
    vector<vector<int>>Search_Word(vector<vector<char>>&grid,string word)
    {
        int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>>ans;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if( left(grid,word,i,j) || right(grid,word,i,j) || 
                    up(grid,word,i,j) || down(grid,word,i,j) || 
                    leftDown(grid,word,i,j) || leftUp(grid,word,i,j)
                    || rightDown(grid,word,i,j)||rightUp(grid,word,i,j) ) 
                    {
                        ans.push_back({i,j});
                    }  
            }
        }
        
        return ans;
    }
};


int main()
{
    vector<vector<char>>grid
    {
        {'a','b','a','b'},{'a','b','e','b'},{'e','b','e','b'}
    };

    string word="abe";

    ques23 q;
    vector<vector<int>>ans=q.Search_Word(grid,word);

    //print vector
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }
}