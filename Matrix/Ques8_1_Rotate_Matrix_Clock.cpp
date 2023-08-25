#include<iostream>
#include<vector>
using namespace std;

class ques8_1
{
    public:
    void rotate_clock(vector<vector<int>>&matrix)
    {
        
        int n=matrix.size();
        int m=matrix[0].size();

        //step-1->transpose
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Step-2 swap [0][0] ->[0][3]
        //       swap[0][1] -> [0][2]
        //like wise for each row
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                swap(matrix[i][j],matrix[i][m-1-j]);
            }
        }
    }
};


int main()
{
    vector<vector<int>>matrix
    {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };

    ques8_1 q;
    q.rotate_clock(matrix);

    for(auto i:matrix)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }


    return 0;
}