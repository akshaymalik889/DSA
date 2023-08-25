#include<iostream>
#include<vector>
using namespace std;

class ques2
{
    public:
    int palindrome_String(string str)
    {
         
        int length=str.length();
	    
	    int i=0,j=length-1;
	    while(i<j)
	    {
	        if(str[i]==str[j])
	        {
	            i++;
	            j--;
	        }
	        else
	        return 0;
	    }
	    return 1;
        
    }
};


int main()
{
    string str="abbbaa";

    ques2  q;
    cout<<q.palindrome_String(str);


    return 0;
}