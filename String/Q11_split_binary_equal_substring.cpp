#include<iostream>
#include<vector>
using namespace std;

class ques11
{
    public:
    int binary_substring(string str)
    {
        int zero=0;
        int one=0;

        int count=0;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='0')
            zero++;
            else
            one++;

            if(zero==one)
            {
                count++;
                zero=0;
                one=0;
            }
        }
        return count;
    }
};


int main()
{
    string str="0100110101";
    vector<string>ans;

    ques11 q;
    cout<<q.binary_substring(str);

    return 0;
}