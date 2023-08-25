#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ques19
{
    public:
    void bishu_Soldiers(vector<int>soldiers,vector<int>queries,vector<pair<int,int>>&ans)
    {
        //STEP-1 -> sort if not sorted
        sort(soldiers.begin(),soldiers.end());

        //STEP-2 -> create prefix sum array
        int n=soldiers.size();
        int prefixSum[n+1];
        prefixSum[0]=0;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum=sum+soldiers[i];

            prefixSum[i+1]=sum;
        }

        //now find sol upto n queries
        int k=0;
        for(auto i:queries)
        {
            //it return iterator
            auto idx=upper_bound(soldiers.begin(),soldiers.end(),i);
            int index=(idx - soldiers.begin());
            ans[k].first=index;
            ans[k].second=prefixSum[index];
            k++;
        }
    }
};


int main()
{
    vector<int>soldiers={1,2,3,4,5,6,7};
    vector<int>queries={3,10,2};

    vector<pair<int,int>>ans(queries.size());

    ques19 q;
    q.bishu_Soldiers(soldiers,queries,ans);

    //print
    for(auto i:ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}