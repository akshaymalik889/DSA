#include<iostream>
using namespace std;

class ques5
{
    public:
    void move_negative(int * arr,int n)
    {
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                swap(arr[i],arr[k]);
                k++;
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    int *arr=new int [100];
    int n;
    cout<<"enter no of elments:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int val;
        cout<<"enter val:";
        cin>>val;
        arr[i]=val;
    }

    ques5 q;
    
    q.move_negative(arr,n);

    
}