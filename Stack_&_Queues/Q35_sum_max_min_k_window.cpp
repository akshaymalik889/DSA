#include<iostream>
#include<queue>

using namespace std;

class question
{
    public:

    int find_maxi_mini(int arr[],int n,int k)
    {
        queue<int>maxi;
        queue<int>mini;

        //first k size window

        for(int i=0;i<k;i++)
        {
            while(!maxi.empty() && arr[maxi.front()]<=arr[i])
            {
                maxi.pop();
            }
            maxi.push(i);

            while(!mini.empty() && arr[mini.front()]>= arr[i])
            {
                mini.pop();
            }
            mini.push(i);
        }

        //store ans
        int ans=0;
        ans=ans+arr[maxi.front()]+arr[mini.front()];

    
        for(int i=k;i<n;i++)
        {
            //before process next window delete unwanted index
            while(!maxi.empty() && i- maxi.front()>=k)
            maxi.pop();

            while(!mini.empty() && i- mini.front()>=k)
            mini.pop();

            //addition of next element
             while(!maxi.empty() && arr[maxi.front()]<=arr[i])
            {
                maxi.pop();
            }
            maxi.push(i);

            while(!mini.empty() && arr[mini.front()]>= arr[i])
            {
                mini.pop();
            }
            mini.push(i);

             ans=ans+arr[maxi.front()]+arr[mini.front()];

        }
        return ans;
    }
};



int main()
{
    question q;

    int arr[]={2,5,-1,7,-3,-1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;

    cout<<q.find_maxi_mini(arr,size,k)<<endl;

    return 0;
}