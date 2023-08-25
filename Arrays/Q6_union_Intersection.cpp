#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class ques6
{
    public:
    void union_intersection(int * arr1,int n,int * arr2,int m)
    {
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[arr1[i]]++;
        }

        //for union
        // for(int i=0;i<n;i++)
        // {
        //     mp[arr1[i]]++;
        // }

        //for intersection
        set<int>s;
        int count=0;
        for(int i=0;i<m;i++)
        {
            s.insert(arr2[i]);
        }
        
        for(auto i:s)
        {
            if(mp.find(i)!=mp.end())
            count++;
        }

        cout<<"count of union="<<mp.size();
        cout<<"count of intersection="<<count;
    }
};

int main ()
{
    int *arr1=new int[100];
    int *arr2=new int[100];

    int n,m;
    cout<<"enter size of array 1:";
    cin>>n;
    cout<<"enter size of array 2:";
    cin>>m;

    for(int i=0;i<n;i++)
    {
        cout<<"enter value:";
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cout<<"enter value:";
        cin>>arr2[i];
    }

    ques6 q;
    q.union_intersection(arr1,n,arr2,m);

    return 0;
}