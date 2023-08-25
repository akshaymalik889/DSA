#include<iostream>
using namespace std;


class ques12
{
    private:
    void fixarray2(int arr2[],int n2)
    {
        for(int i=1;i<n2;i++)
        {
            if(arr2[i]<arr2[i-1])
            swap(arr2[i],arr2[i-1]);
        }
    }

    public:
    void merge2sorted(int arr1[],int n1,int arr2[],int n2)
    {
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);

                //now check array 2 must be sorted
                fixarray2(arr2,n2);
            }
            i++;
        }

        cout<<"array 1 is...."<<endl;
        for(int i=0;i<n1;i++)
        {
            cout<<arr1[i]<<" ";
        }

        cout<<"\narray 2 is...."<<endl;
        for(int i=0;i<n2;i++)
        {
            cout<<arr2[i]<<" ";
        }
    }
};


int main()
{
    int arr1[]={1,3,5,7};
    int arr2[]={0,2,6,8,9};
    int n1=4;
    int n2=5;

    ques12 q;
    q.merge2sorted(arr1,n1,arr2,n2);

    return 0;
}