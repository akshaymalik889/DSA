#include<iostream>
#include<queue>
using namespace std;


class ques14
{
    public:
    long long min_cost_rope(long long arr[],long long n)
    {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }

        long long ans=0;

        while(pq.size()>1)
        {
            long long a=pq.top();
            pq.pop();

            long long b=pq.top();
            pq.pop();

            long long sum=a+b;

            ans=ans+sum;

            pq.push(sum);
        }
        return ans;
    }
};

int main()
{
    long long arr[]={4,3,2,6};
    long long n=4;

    ques14 q;

    cout<<q.min_cost_rope(arr,n);
    
    return 0;
}