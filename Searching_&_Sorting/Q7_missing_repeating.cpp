#include<iostream>
using namespace std;

class ques7
{
    public:
    int* missing_repeating(int arr[],int n)
    {
        int repeated;
        int missing;

        int *a=new int[2];
        //for repeating find
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1] < 0)
            repeated=abs(arr[i]);

            else
            {
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
        }

        //for missing find
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                missing=i+1;
                break;
            }
        }
        a[0]=repeated;
        a[1]=missing;

        return a;
    }
};

int main()
{
    int arr[]={2,4,1,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques7 q;
    int *a=q.missing_repeating(arr,n);

    //print
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++)
    {
        cout<<*a<<endl;
        a++;
    }

    return 0;
}