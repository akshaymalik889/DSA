#include<iostream>
using namespace std;


class ques25
{
    private:
    bool solve(int arr[],int n,int m,int mid)
    {
        int sum=0;
        int student=1;

        for(int i=0;i<n;i++)
        {
            //no can read bcoz one book pages is greater than mid
            if(arr[i]>mid)
            return false;

            if(sum+arr[i]>mid)
            {
                student++;
                sum=arr[i];

                if(student>m)
                return false;
            }
            else
            sum=sum+arr[i];
        }
        return true;
    }


    public:
    int book_allocation(int arr[],int n,int m)
    {
        int low=0;
        int ans=0;
        int high=0;

        //finding high by doing all sum
        for(int i=0;i<n;i++)
        high=high+arr[i];


        //dividing pages

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(arr,n,m,mid))
            {
                //possible ans 
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

};


int main()
{
    int arr[]={12,34,67,90};
    int n=sizeof(arr)/sizeof(arr[0]);

    int m=2;

    ques25 q;
    cout<<q.book_allocation(arr,n,m);

    return 0;
}

