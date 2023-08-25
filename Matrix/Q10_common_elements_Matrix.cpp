#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


class ques10
{
    public:
    vector<int> common_elements(vector<vector<int>>matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int>ans;

        unordered_map<int,int>m;

        //push first row in map
        for(int i=0;i<col;i++)
        {
            m[matrix[0][i]]=1;
        }

        //start finding from 2nd row
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(m.count(matrix[i][j]) && i==m[matrix[i][j]])
                m[matrix[i][j]]++;
            }
        }

        //count which have equal to row here 4 row  are the common elements
        for(auto i:m)
        {
            if(i.second==row)
            {
                ans.push_back(i.first);
            }
        }

        // for(auto i:m)
        // {
        //     cout<<i.first<<" "<<i.second<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};

int main()
{
    vector<vector<int>>matrix
    {
        {1,2,1,4,8},{8,7,8,5,1},{8,7,7,3,1},{8,1,2,7,9}
    };

    ques10 q;
    vector<int>ans=q.common_elements(matrix);
    
    //print
    for(auto i:ans)
    cout<<i<<" ";


}