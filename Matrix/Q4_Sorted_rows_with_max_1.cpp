#include<iostream>
#include<vector>
using namespace std;


class ques4
{
    public:

    //Approach -3 if 0 then skip row, else move left
    int max__row_App_3(vector<vector<int>>matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();

        int max_row=-1;

        //traverse matrix row wise
	    for(int i=0;i<row;i++)
	    {
	        for(int j=col-1;j>=0;j--)
	        {
	            if(matrix[i][j]==1)
	            {
	                max_row=i;
	                
	                //we also decrement col bcoz for next rows
	                //we not see this col again
	                col--;
	            }
	            else
	            {
	                //if 0 comes we simple skip that row
	                break;
	            }
	            
	        }
	    }
	    return max_row;

    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}
    };

    ques4 q;
    cout<<q.max__row_App_3(matrix);


}