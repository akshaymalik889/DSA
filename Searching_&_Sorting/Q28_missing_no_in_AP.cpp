#include<iostream>
using namespace std;


class ques28
{
    public:
    int missing_AP(int A,int B,int C)
    {
        if(C==0)
        {
            if(A==B)
            return 1;

            else
            return 0;
        }
        else
        {
            //negative
            if( (B-A)/C < 0)
            return 0;
            
            else
            {
                //divisible
                if( (B-A)%C == 0 )
                return 1;
                
                else
                return 0;
            }
            
        }
    }
};


int main()
{
    int A=1;
    int B=3;
    int C=2;

    ques28 q;
    cout<<q.missing_AP(A,B,C);

    return 0;
}