#include<iostream>
using namespace std;

class ques11
{
    public:
    void findDuplicate(int arr[],int n)
    {
        //adding n to each value
        //so if it repeats then there n add two times
        //then we just normal divide each number by n 
        //if then greater than 1 then means it is reapeated
        for(int i=0;i<n;i++)
        {
            arr[arr[i]%n]=arr[arr[i]%n]+n;
        }

        for(int i=0;i<n;i++)
        {
            if(arr[i]/n>1)
            {
                cout<<"repeating no is:"<<i<<endl;
                break;
            }
        }

        

    }
};

int main()
{
    int arr[]={1,3,4,2,2};
    int n=5;

    ques11 q;
    q.findDuplicate(arr,n);

    return 0;
}