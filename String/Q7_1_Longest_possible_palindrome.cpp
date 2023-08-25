#include<iostream>
#include<unordered_map>
using namespace std;

class ques7_1
{
    public:
    int longest_Palindrome(string s)
    {
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
        }

        int cnt=0;
        for(auto i:map)
        {
            if(i.second%2!=0)
            {
                cnt++;
            }
        }
        if(cnt>1)
        {
            return s.length()-cnt+1;
        }

        return s.length();

    }
};

int main()
{
    string str="bbbad";

    ques7_1 q;
    cout<<q.longest_Palindrome(str);


    return 0;
}