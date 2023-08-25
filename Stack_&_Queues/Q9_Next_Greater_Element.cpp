#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class ques9
{
    public:
    vector<int>nextGreater(int arr[],int n)
    {
        stack<int>s;
        s.push(-1);

        vector<int>ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(s.top()!=-1 && s.top()<=arr[i])
            s.pop();

            ans[i]=s.top();
            s.push(arr[i]);
        }
        return ans;
    }
} ;

int main()
{
    int arr[]={1,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques9 q;

    vector<int>ans=q.nextGreater(arr,n);

    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}