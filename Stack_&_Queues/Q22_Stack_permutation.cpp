#include<iostream>
#include<stack>
using namespace std;


class ques22
{
    public:
    int stack_permutaion(int A[],int B[],int n)
    {

        stack<int>s;;
        int j=0;
        
        for(int i=0;i<n;i++)
        {
            s.push(A[i]);
            
            if(s.top()==B[j])
            {
                while(!s.empty() && s.top()==B[j])
                {
                    s.pop();
                    j++;
                }
            }
        }
        
        if(s.size()==0)
        return 1;
        
        else
        return 0;
    }
};


int main()
{
    int A[]={1,2,3};
    int B[]={2,1,3};
    int n=sizeof(A)/sizeof(A[0]);

    ques22 q;

    cout<<q.stack_permutaion(A,B,n);

    return  0;
}