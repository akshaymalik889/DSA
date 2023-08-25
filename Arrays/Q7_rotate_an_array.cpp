#include<iostream>
using namespace std;

class ques7
{
    public:
    void rotateArray(int arr[],int n)
    {
        int temp=arr[n-1];

        for(int i=n-1;i>0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=temp;

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }


    void rotateArray_by_k(int arr[],int n,int k)
    {
        int arr2[n];
        for(int i=0;i<n;i++)
        {
            arr2[(i+k)%n]=arr[i];
        }

        for(int i=0;i<n;i++)
        {
            cout<<arr2[i]<<" ";
        }
    }
};

int main()
{
    int *arr=new int[100];

    int n;
    cout<<"enter values you want:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int val;
        cout<<"enter value:";
        cin>>val;
        arr[i]=val;
    }
    
    ques7 q;
    
    q.rotateArray(arr,n);
    
    int k=3;

    cout<<"\narray rotate by k..."<<endl;
    q.rotateArray_by_k(arr,n,k);
    return 0;


}