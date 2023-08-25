#include<iostream>
#include<Set>
using namespace std;

class ques24
{
    public:
    int longest_sequence_ap2(int arr[],int n)
    {
        set<int>s;

        //step 1: insert in set
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }

        //step 2: find in set if  arr[i]-1 is present or not
        //if present: i++;
        //if not present: find until val++ present and increase count.
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            int val=arr[i]-1;
            if(!s.count(val)) 
            {
                while(s.count(++val))
                count++;

                maxi=max(maxi,count);
            }
        } 
        return maxi;
    }
};

int main()
{
    int arr[]={4,1,7,2,3,8};
    int n=6;

    ques24 q;
    cout<<q.longest_sequence_ap2(arr,n);

    return 0;
}