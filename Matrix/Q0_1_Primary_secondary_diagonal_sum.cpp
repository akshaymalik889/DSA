#include<iostream>
#include<vector>
using namespace std;

class ques0_1
{
    public:

    //Approach-1 (two loops)
    int diagonal_primary_secondary_APP_1(vector<vector<int>>&matrix)
    {
        int sum=0;
        int n=matrix.size();
        
        //for secondary diagonal
        int k=n-1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    sum=sum+matrix[i][j];
                }
                
                if(j==n-1)
                {
                    sum=sum+matrix[i][k];
                    k--;
                }
            }
        }

        //case when mid of matrix is added twice 
        //in primary diagonal and secondary diagonal also
        //so we deduct 1 time
        if(n%2==1)
        {
            sum=sum-matrix[n/2][n/2];
        }
        
        return sum;
    }


    //Approach-2 (only one loops)
    int diagonal_primary_secondary_APP_2(vector<vector<int>>&matrix)
    {
        int n = matrix.size();

        int sum = 0;
        
        for( int i = 0 ; i < n ; i++ )
        {
            // primary diagonal
            sum=sum + matrix[i][i];
            
            // secondary diagonal
            sum=sum + matrix[n-1-i][i];
        }
        
        if( n % 2 == 1 )
        {
            // remove center element (repeated) on odd side-length case
            sum=sum- matrix[n/2][n/2];
        }
        return sum;
    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {1,2,3},{4,5,6},{7,8,9}
       // {1,2},{-9,-2}
    };

    ques0_1 q;
    //cout<<q.diagonal_primary_secondary_APP_1(matrix);
    cout<<q.diagonal_primary_secondary_APP_2(matrix);
    return 0;
}