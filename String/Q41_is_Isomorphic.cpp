#include<iostream>
#include<unordered_map>
using namespace std;

class ques41
{
    public:
    bool is_Isomorphic(string str1,string str2)
    {
        int n=str1.length();
        int m=str2.length();

        if(n!=m)
        return false;

        unordered_map<char,char>m1;
        unordered_map<char,char>m2;

        for(int i=0;i<n;i++)
        {
            //if char comes in str1 and str2 first time then we do map them
            if( m1.count(str1[i])==0 && m2.count(str2[i])==0 )
            {
                m1[str1[i]]=str2[i];
                m2[str2[i]]=str1[i];
            }
            
            //else character already map so we check :is it map to same old char or not
            else if(m1[str1[i]]!=str2[i])
            return false;
        }
        return true;  
    }
};

int main()
{
    string str1="egg";
    string str2="add";

    ques41 q;
    cout<<q.is_Isomorphic(str1,str2);
    
    return 0;
}