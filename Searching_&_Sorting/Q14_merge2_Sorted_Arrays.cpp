#include<iostream>
#include<algorithm>
using namespace std;


class ques14
{
    public:
    void merge2Arrays(int arr1[],int arr2[],int n1,int n2)
    {
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);

                //now sort 2nd array
                sort(arr2,arr2+n2);
            }
            else
            i++;
        }
    }
};

int main()
{
    int arr1[]={1,3,5,7};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={0,2,6,8,9};
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    ques14 q;
    q.merge2Arrays(arr1,arr2,n1,n2);

    //merge in first array so we print now
        for(int i=0;i<n1;i++)
        cout<<arr1[i]<<" ";

        for(int i=0;i<n2;i++)
        cout<<arr2[i]<<" ";

    return 0;
}