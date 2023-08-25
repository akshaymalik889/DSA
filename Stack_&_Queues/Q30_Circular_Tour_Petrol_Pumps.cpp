#include<iostream>
#include<vector>
using namespace std;

struct petrolpump
{
    int petrol;
    int distance;
};

class ques30
{
    public:
    int Circular_Tour(petrolpump arr[],int n)
    {
        int bal=0;
        int dificit=0;
        int start=0;

        for(int i=0;i<n;i++)
        {
            bal=bal + (arr[i].petrol - arr[i].distance);

            if(bal<0)
            {
                dificit=bal + dificit;
                start= i + 1;
                bal=0;
            }
        }

        if(dificit + bal >= 0)
        return start;

        else
        return -1;
    }
};

int main()
{
    int n=4;
   // vector<pair<int,int>>p={{7,6},{8,7},{5,8},{11,9},{17,7},{6,5}};
    petrolpump arr[n]={{4,6},{6,5},{7,3},{4,5}};
   
   ques30 q;
   cout<<q.Circular_Tour(arr,n);

}