#include<iostream>
using namespace std;


class ques29
{
    private:
    bool fact(int mid,int n)
        {
            int prod=5;
            int count=0;
            
            while(prod<=mid)
            {                            // mid     //product
                count=count+(mid/prod);  // 15       // 5              //15/5=3
                prod=prod*5;                         //5*5=25        //15/25=false
            }
            
            if(count>=n)
            return true;
            
            else
            return false;
        }

    public:
    int smallest_Fact(int n)
    {
        if(n==1)
        return 5;
            
            //using binary search
            int low=0;
            int high=5*n;
            
            while(low<high)
            {
                int mid=low+(high-low)/2;
                
                //fact function to calculate Trailing Zeroes
                if( fact(mid,n) )
                high=mid;
                
                else
                low=mid+1;
            }
            return low;
    }
};


int main()
{
    int n=6;

    ques29 q;
    cout<<q.smallest_Fact(n);

    return 0;
}