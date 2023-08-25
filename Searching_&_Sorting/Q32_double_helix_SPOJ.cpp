#include<iostream>
using namespace std;


class ques32
{
    public:
    int double_helix(int seq1[],int n1,int seq2[],int n2)
    {
        int sum1=0;
        int sum2=0;

        int i=0;
        int j=0;

        int ans=0;

        while(i<n1 && j<n2)
        {
            if(seq1[i]<seq2[j])
            {
                sum1=sum1 + seq1[i];
                i++;
            }
            else if(seq2[j]<seq1[i])
            {
                sum2=sum2 + seq2[j];
                j++;
            }
            else  //same element ->bridge
            {
                ans=ans + max(sum1,sum2) + seq1[i];
                
                sum1=0;
                sum2=0;
                i++;
                j++;
            }

        }

        while(i<n1)
        {
            sum1=sum1 + seq1[i];
            i++;
        }

        while(j<n2)
        {
            sum2=sum2 + seq2[j];
            j++;
        }

        ans=ans + max(sum1,sum2);

        return ans;
    }
};

int main()
{
    int seq1[]={3,5,7,9,20,25,30,40,55,56,57,60,62};
    int n1=sizeof(seq1)/sizeof(seq1[0]);

    int seq2[]={1,4,7,11,14,25,44,47,55,57,100};
    int n2=sizeof(seq2)/sizeof(seq2[0]);

    ques32 q;
    cout<<q.double_helix(seq1,n1,seq2,n2);

    return 0;
}