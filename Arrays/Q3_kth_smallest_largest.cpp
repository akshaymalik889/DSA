#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class ques3
{
    public:
    //Approach -1 (Sorting)
    void kth_smallest_ap_1(int *arr,int n,int k)
    {
        sort(arr,arr+n);

        cout<<"kth smallest="<<arr[k-1]<<endl;

    }

    //Approach -2(Heaps)
    void kth_smallest_ap_2(int * arr,int n,int k)
    {
        priority_queue<int>pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }

        for(int i=k;i<n;i++)
        {
            if(pq.top()>arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        cout<<pq.top();
    }
};


int main()
{
    int *arr=new int [100];
    int n;
    cout<<"enter no of elments:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int val;
        cout<<"enter val:";
        cin>>val;
        arr[i]=val;
    }
    int k=3;

    ques3 q;
    //q.kth_smallest_ap_1(arr,n,k);
    q.kth_smallest_ap_2(arr,n,k);

    
}