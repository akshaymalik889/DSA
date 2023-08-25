#include<iostream>
#include<vector>
using namespace std;

class ques2
{
    public:
    vector<int>value_Equal_Index(vector<int>arr)
    {
        vector<int>ans;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==i+1)
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


int main()
{
    vector<int>arr{15, 2, 45, 12, 7};

    ques2 q;
    vector<int>ans=q.value_Equal_Index(arr);

    //print
    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}