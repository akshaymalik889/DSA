#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class ques33
{
    private:
    char getMaxCountChar(unordered_map<char,int>&m)
    {
        int max = 0;
        char ch;

        for(auto i:m)
        {
            if(i.second>max)
            {
                max=i.second;
                ch=i.first;
            }    
        }
        //cout<<ch<<endl;
        return ch;
    }
    
    
    public:
    string rearrange_Adjacent(string str)
    {
        int N = str.size();
        if (N == 0)
        return "";
 
        unordered_map<char,int>m;
        for (int i=0;i<str.length();i++)
        m[str[i]]++;
 
        char ch_max = getMaxCountChar(m);
        int maxCount = m[ch_max];
 
        // check if the result is possible or not
        if (maxCount > (N + 1) / 2)
        return "";
 
        string res(N, ' ');
        int index = 0;
 
        // filling the most frequently occurring char in the
        // even indices
        while (maxCount) 
        {
            res[index] = ch_max;
            index = index + 2;
            maxCount--;
        }
 
        m[ch_max]= 0;
 
        // now filling the other Chars, first
        // filling the even positions and then
        // the odd positions
        for (auto i:m) 
        {
             while (i.second > 0) 
            {

                if(index >= N)
                index=1;
                
                res[index] = i.first;
                index += 2;
                i.second--;
            }
        }
        return res;
    }
};

int main()
{
    string str="bbbaa";

    ques33 q;
    string ans=q.rearrange_Adjacent(str);

    if(ans=="")
    cout<<"NOT POSSIBLE";
    else
    cout<<ans<<endl;


    return 0;
}