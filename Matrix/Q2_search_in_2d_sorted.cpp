#include<iostream>
#include<vector>
using namespace std;


class ques2
{
    public:

    //Approach-1 brute force
    bool search_val_AP_1(vector<vector<int>>matrix,int x)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==x)
                return true;
            }
        }
        return false;
    }

    //Approach-2 using i & j pointer
    bool search_val_AP_2(vector<vector<int>>matrix,int x)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        int i=0;
        int j=m-1;
        
        while(i<n && j>=0)
        {
            if(matrix[i][j]==x)
            return true;

            if(matrix[i][j]>x)
            j--;
            else
            i++;
        }
        return false;
    }


    //Approach-3 Binary Search
    bool search_val_AP_3(vector<vector<int>>matrix,int x)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int low=0;
        int high=row*col-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int element=matrix[mid/col][mid%col];
            
            if(element==x)
                return true;
            if(element<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};


int main()
{
    
    vector<vector<int>>matrix
    {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };
    int x=3;

    ques2 q;
    //cout<<q.search_val_AP_1(matrix,x);
    //cout<<q.search_val_AP_2(matrix,x);
    cout<<q.search_val_AP_3(matrix,x);


}