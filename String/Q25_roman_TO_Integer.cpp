#include<iostream>
#include<unordered_map>

using namespace std;

class ques25
{
    public:
    int roman_to_Integer(string str)
    {
        unordered_map<char,int>m{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int ans=0;
        
        for(int i=0;i<str.length();i++)
        {
            if(m[str[i]] < m[str[i+1]])
            ans=ans - m[str[i]];
            
            else
            ans= ans +  m[str[i]];
        }
        return ans;
    }
};

int main()
{

    string str="CMXVI";

    ques25 q;
    cout<<q.roman_to_Integer(str);


    return 0;
}