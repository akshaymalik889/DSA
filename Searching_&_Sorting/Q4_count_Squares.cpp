#include<iostream>
#include<math.h>
using namespace std;


class ques4
{
    public:

    //Approach-1
    int countSquares_App1(int N)
    {
        int k=sqrt(N);
        int count=0;
        
        for(int i=1;i<=k;i++)
        {
            int square=i*i;
            if(square<N)
            count++;
        }
        return count;
    }
    int countSquares_App2(int N)
    {
         int count=0;
        
        for(int i=1;i*i<N;i++)
        {
            if(i*i<N)
            count++;
        }
        return count;
    }
};


int main()
{
    int N=9;

    ques4 q;
    //cout<<q.countSquares_App1(N);
    cout<<q.countSquares_App2(N);


    return 0;
}