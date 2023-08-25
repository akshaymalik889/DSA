#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class ques8
{
    public:

        int kth_largest_sum_Approach_1(int arr[],int n,int k)
        {
            vector<int>v;

            for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=i;j<n;j++)
                {
                    sum=sum+arr[j];
                    v.push_back(sum);
                }
            }

            sort(v.begin(),v.end());

            for(auto i:v)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            int size=v.size();
            return v[size-k];
        }

        int kth_largest_sum_Approach_2(int arr[],int n,int k)
        {
            priority_queue<int,vector<int>,greater<int>>pq;

            
            for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=i;j<n;j++)
                {
                    sum=sum+arr[j];

                    if(pq.size()<k)
                    {
                        pq.push(sum);
                    }
                    else
                    {
                        if(sum>pq.top())
                        {
                            pq.pop();
                            pq.push(sum);
                        }
                    }
                   
                }
            }
            return pq.top();
        }
};

int main()
{

    int arr[]={20, -5, -1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    ques8 q;
    cout<<q.kth_largest_sum_Approach_1(arr,n,k);
    cout<<q.kth_largest_sum_Approach_2(arr,n,k);
    return 0;
}