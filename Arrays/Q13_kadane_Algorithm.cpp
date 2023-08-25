#include<iostream>
using namespace std;

class ques13
{
    public:
    int kadane_algo(int arr[],int n)
    {
        int curSum=0,maxi=INT_MIN;

        for(int i=0;i<n;i++)
        {
            curSum=curSum+arr[i];

            maxi=max(maxi,curSum);

            if(curSum<0)
            curSum=0;
        }
        return maxi;
    }
};


int main()
{
    int arr[]={1,2,3,-2,5};
    int n=5;

    ques13 q;
    cout<<q.kadane_algo(arr,n);


    return 0;
}