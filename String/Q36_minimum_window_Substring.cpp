#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;


class ques36
{
    public:

    string minimum_Window_substring(string &s,string &p)
    {

        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        
        //push s string in map
        for(int i=0;i<p.length();i++)
        {
            m1[p[i]]++;
        }

        int n=m1.size();
        int count=0;
        
        //check if s[0] is in map or not
        if(m1.count(s[0]))
        {
            m2[s[0]]++;
            
            if(m1[s[0]]==m2[s[0]])
            count++;
        }

        int i=0;
        int j=1;
        int start=0;
        int ans=INT_MAX;

        while(i<=j && j<s.length())
        {
            if(count==n)
            {
                if(j-i<ans)
                {
                    ans=j-i;
                    start=i;
                }  
                
                
                //start shrinking i
                if(m1.count(s[i]))
                {
                    if(m1[s[i]]==m2[s[i]])
                    count--;

                    m2[s[i]]--;
                }
                i++;
            }
            
            else
            {
                if(m1.count(s[j]))
                {
                    
                    m2[s[j]]++;
        
                    if(m1[s[j]]==m2[s[j]])
                    count++;
                }
                j++;
            }
        }

        //if in end count ==n -> then we try to minimize i
        while(count==n)
        {
         
            if(j-i<ans)
            {
                ans=j-i;
                start=i;
            }  

            if(m1.count(s[i]))
            {
                if(m1[s[i]]==m2[s[i]])
                count--;

                m2[s[i]]--;
            }
            i++;
        }   

      if(ans!=INT_MAX)  
      return s.substr(start,ans);
      else
      return "";
    }
};

int main()
{
    string s="timetopractice";
    string p="tto";

    ques36 q;
    cout<<q.minimum_Window_substring(s,p);

    return 0;



}
