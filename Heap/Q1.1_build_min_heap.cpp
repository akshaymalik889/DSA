#include<iostream>
using namespace std;


class ques1
{
    public:

    void heapify(int arr[],int n,int i)
    {
        int smallest=i;

        int left=2*i+1;
        int right=2*i+2;

        if( left<n && arr[left] < arr[smallest] )
        smallest=left;

        if( right<n && arr[right] < arr[smallest] )
        smallest=right;

        //it means we find child smaller
        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);

            heapify(arr,n,smallest);
        }

    }
   void buildheap(int arr[],int n)
   {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(arr,n,i);
        }
   }

   void printheap(int arr[],int n)
   {
        cout<<"MIN heap is..."<<endl;
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

        cout<<endl;
   }
};


int main()
{
    int arr[]={10,20,25,6,12,15,4,16};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques1 q;
    q.buildheap(arr,n);
    q.printheap(arr,n);

    return 0;
}