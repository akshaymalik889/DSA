#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ques5
{
    public:
    void sorted_matrix(vector<vector<int>>&matrix)
    {
        int N=matrix.size();
        vector<int>v;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                v.push_back(matrix[i][j]);
            }
        }
        
        sort(v.begin(),v.end());
        
        int k=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                matrix[i][j]=v[k];
                k++;
            }
        }
        
    }

};

int main()
{
    vector<vector<int>>matrix
    {
        {10,20,30,40},{15,25,37,45},{27,29,37,48},{32,33,39,50}
    };

    ques5 q;
    q.sorted_matrix(matrix);

    //print matrix;
    for(auto i:matrix)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }


}