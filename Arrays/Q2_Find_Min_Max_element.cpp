#include<iostream>
#include<limits.h>
using namespace std;

class ques2
{
    public:
    void find_min_max(int * arr,int n)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<n;i++)
        {
            maxi=max(arr[i],maxi);
            mini=min(arr[i],mini);
        }
        cout<<"max element="<<maxi<<endl;
        cout<<"min element="<<mini<<endl;
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

    ques2 q;
    q.find_min_max(arr,n);

    
}
