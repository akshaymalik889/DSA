#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ques21
{
    public:
    void kth_smallest_again(vector<pair<int,int>>queries,vector<int>k)
    {
        //step-1 sort array
        sort(queries.begin(),queries.end());

        //step-2 merge interals
        int index=0;
        
        for(int i=1;i<queries.size();i++)
        {
            if(queries[index].second>=queries[i].first)
            {
                queries[index].second=max(queries[index].second,queries[i].second);
            }
            else
            {
                index++;
                queries[index]=queries[i];
            }
        }

        //step-3 process upto kth values

        for(int i=0;i<k.size();i++)
        {
            int ans=-1;
            for(int j=0;j<=index;j++)
            {
                //finding difference

                //here means  lies in range
                if( (queries[j].second - queries[j].first + 1) >=k[i] )
                {
                    ans=queries[j].first + k[i] - 1 ;
                    break;
                }
                
                else
                {
                    //not lies in range so we update k by subtract diff
                    k[i]=k[i] - (queries[j].second - queries[j].first + 1);
                }
            }
            cout<<ans<<endl;
        }
    }
};


int main()
{
    vector<pair<int,int>>queries={{1,3},{1,5}};
    vector<int>k={1,3,6};

    ques21 q;
    q.kth_smallest_again(queries,k);

    return 0;
}