#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ques11
{
    public:
    vector<vector<int>>Sum4(vector<int>arr,int target)
    {
        sort(arr.begin(),arr.end());

        vector<vector<int>>ans;
        int n=arr.size();
        
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
            continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && arr[j]==arr[j-1])
                continue;
                
                int start=j+1;
                int end=n-1;
                int sum=target-(arr[i]+arr[j]);
               
                while(start<end)
                {
                    int s=arr[start]+arr[end];

                    if(s==sum)
                    {
                        vector<int>v={arr[i],arr[j],arr[start],arr[end]};
                        ans.push_back(v);
                        
                        while( start<end && arr[start]==arr[start+1] )
                        start++;
                        
                        while( start<end && arr[end]==arr[end-1] )
                        end--;

                        start++;
                        end--;
                    }

                    else if(s<sum)
                    start++;

                    else
                    end--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int>arr={1,0,-1,0,-2,2};
    int target=0;

    ques11 q;
    vector<vector<int>>ans=q.Sum4(arr,target);

    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}