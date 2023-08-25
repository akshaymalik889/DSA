#include<iostream>
using namespace std;

class ques9
{
    public:
    int search_x(int arr[],int n,int x,int k)
    {
        for(int i=0;i<n;)
        {
            if(arr[i]==x)
            return i;

            int diff=abs(arr[i]-x);

            i=i+max(1,diff/k);
        }
        return -1;

    }
};

int main()
{
    int arr[]={5,6,7,9,11,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    int x=11;
    int k=2;

    ques9 q;
    cout<<q.search_x(arr,n,x,k);

    return 0;
}