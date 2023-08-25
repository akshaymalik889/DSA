#include<iostream>
#include<vector>
using namespace std;

class ques8_0
{
    public:
    void rotate_anticlock(vector<vector<int>>&matrix)
    {
        //we see carefully
        //row convert into column in reverse order

        //we traverse boundry wise
        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                //store first element
                int temp=matrix[i][j];
                
                matrix[i][j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=temp;
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

    ques8_0 q;
    q.rotate_anticlock(matrix);

    for(auto i:matrix)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }


    return 0;
}