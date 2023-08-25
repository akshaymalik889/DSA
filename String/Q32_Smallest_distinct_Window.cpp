#include<iostream>
#include<set>
#include<unordered_map>
#include<limits.h>
using namespace std;


class ques32
{
    public:
    int smallest_window(string str)
    {
        //set for storing all distinct elements
        set<char>s;
        
        for(int i=0;i<str.length();i++)
        s.insert(str[i]);
        
        //storing distinct elements count
        int n=s.size();
        
        unordered_map<char,int>m;
        int count=0;
        int ans=INT_MAX;
        
        //storing first elment in map
        m[str[0]]++;
        count++;
        
        int i=0;
        int j=1;
        
        while(i<=j && j<str.length())
        {
            //means  expand ->so j++;
            if(count<n)
            {
                //not in map
                if(m[str[j]]==0)
                count++;
                
                m[str[j]]++;
                j++;
            }
            //means now we try to close gap and find minimum
            else if(count==n)
            {
                ans=min(ans,j-i);
                
                //means last element left
                if(m[str[i]]==1)
                count--;
                
                m[str[i]]--;
                i++;
            }
        }
        
        while(count==n)
        {
            ans=min(ans,j-i);
                
            //means last element left
            if(m[str[i]]==1)
            count--;
                
            m[str[i]]--;
            i++;
        }
        return ans;
    }
};



int main()
{

    string str="aabcbcdbca";

    ques32 q;
    cout<<q.smallest_window(str);
    return 0;
}