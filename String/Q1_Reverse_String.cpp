#include<iostream>
#include<vector>
using namespace std;

class ques1
{
    public:
    void reverse_String(vector<char>&s)
    {
         
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
};


int main()
{
    vector<char>s{
        {'h','e','l','l','o'}
        };

    ques1  q;
    q.reverse_String(s);

    for(auto i:s)
    cout<<i<<" ";


    return 0;
}
