#include<iostream>
#include<unordered_map>
using namespace std;

class ques3
{
    public:
    void find_duplicates(string str)
    {
        unordered_map<char,int>m;

        int n=str.length();
        int i=0;

        while(i<n)
        {
            m[str[i]]++;
            
            i++;
        }

        //print
        cout<<"duplicates characters..."<<endl;
        for(auto i:m)
        {
            if(i.first!=' ' && i.second>1)
            cout<<i.first<<" ";
        }
    }
};

int main()
{
    string str="geeks for geeks";

    ques3 q;
    q.find_duplicates(str);

    return 0;
}