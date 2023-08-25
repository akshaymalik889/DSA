#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


class ques30
{
    public:
    int chocolate_distribution(vector<int>a,int m)
    {
        int n=a.size();
        int ans=INT_MAX;

        //sort the array
        sort(a.begin(),a.end());

        for(int i=0;i+m-1<n;i++)
        {
            ans=min(ans,a[i+m-1]-a[i]);
        }
        return ans;
    }
}; 

int main()
{

    vector<int>a{3,5,1,9,56,7,9,12};
    int m=5;

    ques30 q;
    cout<<q.chocolate_distribution(a,m);

    return 0;
}