#include<iostream>
#include<memory.h>
using namespace std;

class ques40
{
    public:
    int transform_String(string A,string B)
    {
        //checking transform possible or not
        int s1=0;
        int s2=0;
        int n=A.length();
        int m=B.length();
        
        //checking length
        if(n!=m)
        return -1;

//THIS NOT WORKS IN SOME CASES SO WE USE ARRAY[count] TO CHECK FOR 
//SAME CHARACTERS
        // //checking ASCII sum
        // for(int i=0;i<n;i++)
        // {
        //     s1=s1+A[i];
        // }
        
        // for(int i=0;i<m;i++)
        // {
        //     s2=s2+B[i];
        // }
        
        // cout<<"s1="<<s1<<endl;
        // cout<<"s2="<<s2<<endl;
        // if(s1!=s2)
        // return -1;

        int count[256];
        memset(count, 0, sizeof(count));
        
        // count characters in A
        for (int i = 0; i < n; i++)
        count[A[i]]++;
        
        // subtract count for every character in B
        for (int i = 0; i < n; i++)
        count[B[i]]--;
        
        // Check if all counts become 0
        for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
        
        
        //Possible to Transform
        int c=0;
        for(int i=n-1,j=m-1;i>=0 && j>=0;)
        {
            if(A[i]==B[j])
            {
                i--;
                j--;
            }
            else
            {
                c++;
                i--;
            }
        }
        return c;
    }
};

int main()
{
    string str1="ABD";
    string str2="BAD";

    ques40 q;
    cout<<q.transform_String(str1,str2);
    
    return 0;
}