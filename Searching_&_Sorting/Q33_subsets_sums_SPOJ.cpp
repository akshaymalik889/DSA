#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ques33
{
    private:
    void solve(int arr[],int start,int end,vector<int>&v1)
    {
        int sum=0;

        //finding length
        int n=end-start+1;


        //finding all subsequences//subsets
        for(int i=0;i<(1<<n);i++)
        {
            int sum=0;
            int j=start;
            int x=i;

            while(x>0)
            {
                int l=x&1;

                if(l==1)
                {
                    sum=sum+arr[j];
                }
                j++;
                x=x>>1;
            }
            v1.push_back(sum);
        }
    }

    public:
    int subsets_Sums(int arr[],int n,int A,int B)
    {
        //first half subsets
        vector<int>v1;

        //second half subsets
        vector<int>v2;

        solve(arr,0,(n/2)-1,v1);
        solve(arr,(n/2),n-1,v2);

        sort(v2.begin(),v2.end());

        int count=0;

        for(int i=0;i<v1.size();i++)
        {
            int low=lower_bound(v2.begin(),v2.end(),A-v1[i]) - v2.begin();
            int high=upper_bound(v2.begin(),v2.end(),B-v1[i]) - v2.begin();

            count=count+(high-low);
        }
        return count;
    }
};

int main()
{
    int arr[]={1,5,3,4,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int A=6;
    int B=10;

    ques33 q;
    cout<<q.subsets_Sums(arr,n,A,B);
    
    return 0;
} 