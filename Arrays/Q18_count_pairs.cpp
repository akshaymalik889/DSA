#include<iostream>
#include<unordered_map>
using namespace std;

class ques18
{
    public:
    //APPROACH - 1 (BRUTE FORCE)
    int count_pairs_ap_1(int arr[],int n,int k)
    {
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==k)
                count++;
            }
        }
        return count;
    }

    //APPROACH - 2 (Hashing)
    int count_pairs_ap_2(int arr[],int n,int k)
    {
        int count=0;
        unordered_map<int,int>m;

        for(int i=0;i<n;i++)
        {
            int val=k-arr[i];
            if(m.count(val))
            {
                count=count+m[val];
                m[arr[i]]++;
            }
            else
            m[arr[i]]++;
        }

        //important it give value of corresponding key
        //cout<<m[1];
        return count;
    }
};

int main()
{
    int arr[]={1,1,1,1};
    int n=4;
    int k=2;

    ques18 q;
    //cout<<q.count_pairs_ap_1(arr,n,k);
    cout<<q.count_pairs_ap_2(arr,n,k);

}