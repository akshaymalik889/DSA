#include<iostream>
using namespace std;

class ques1
{
    public:
    void reverseArray(int * arr,int n)
    {
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            swap(arr[i],arr[j]);
        }

        //Reverse Array
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
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
    
    ques1 q;
    q.reverseArray(arr,n);

    return 0;


}