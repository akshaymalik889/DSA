#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int>&v,int n,int i)
{
    int largest=i; 
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && v[left]>v[largest])
    largest=left;

    if(right<n && v[right]>v[largest])
    largest=right;

    if(largest != i)
    {
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }
}

class ques7
{
    
    public:
    vector<int>merge2Heaps(vector<int>v1,vector<int>v2)
    {
        vector<int>v3;
        //step 1:merge both arrays into c
        for(auto i:v1)
        v3.push_back(i);
        
        for(auto i:v2)
        v3.push_back(i);

        //step 2 build max heap now of vector c
        int size=v3.size();

        for(int i=size/2-1;i>=0;i--)
        {
            heapify(v3,size,i);
        }
        
        for(auto i:v3)
        cout<<i<<" ";
    }

};

int main()
{

    vector<int>v1={5,6,2,10};
    vector<int>v2={7,9,12};
    
    int size1=v1.size();
    int size2=v2.size();
    for(int i=size1/2-1;i>=0;i--)
    {
        heapify(v1,size1,i);
    }
     for(int i=size2/2-1;i>=0;i--)
    {
        heapify(v2,size2,i);
    }

    ques7 q;
    q.merge2Heaps(v1,v2);




    return 0;
}