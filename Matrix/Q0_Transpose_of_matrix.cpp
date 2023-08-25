#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques0
{
    public:

    void transpose_matrix(vector<vector<int>>&matrix)
    {
        //transpose always can be calculated in squre matrix ie row==col

        int n=matrix.size();
        int m=matrix[0].size();

        cout<<"row size:"<<n<<endl;
        cout<<"col size:"<<m<<endl;

        for(int i=0;i<n;i++)
        {
            //here j can be j<=i also it means same element swap with itself
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        return ;
    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {1,1,1,1,},{2,2,2,2},{3,3,3,3},{4,4,4,4}
       // {1,2},{-9,-2}
    };

    ques0 q;
    q.transpose_matrix(matrix);

    //print after transpose
    for(auto i: matrix)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }

    return 0;
}