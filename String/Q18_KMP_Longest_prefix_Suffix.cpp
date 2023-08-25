#include<iostream>
#include<vector>
using namespace std;

class ques18
{
    public:
    //Approach-1 ->Simple traversal
    int longest_Prefix_Suffix_Ap_1(string s)
    {
        string a="";
	   string b="";
	    
	   int n=s.length();
	   int ans=0;
	    
	   for(int i=0;i<n-1;i++)
	    {
	       a=a+s[i];
	       b=s[n-i-1]+b;
	        
	       if(a==b)
	       ans=a.length();
	    }
	    
	   return ans;
    }

    //Approach-2 ->KMP algorithm
    int longest_Prefix_Suffix_Ap_2(string s)
    {
        vector<int>A(s.length(),0);
	   int j=0,i=1;
	   
	   while(i<s.length())
	    {
	       if(s[i]==s[j])
	        {
	           A[i]=j+1;
	           j++;
	           i++;
	        }
	       else
	        {
	           if(j==0)
	           i++;
	           else
	           j=A[j-1];
	        }
	    }
	   
	   //return last value of vector
	   return A.back();
    }
};

int main()
{
    string s="abab";

    ques18 q;
    //cout<<q.longest_Prefix_Suffix_Ap_1(s);
    cout<<q.longest_Prefix_Suffix_Ap_2(s);

    return 0;
}