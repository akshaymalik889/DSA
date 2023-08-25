#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class ques35
{
    public:
    vector<vector<string>>All_Anagrams(vector<string>&str)
    {
        unordered_map<string,vector<string>>m;
        
        for(auto i:str)
        {
            string s=i;
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        
        //it tell how many row in vector
        vector<vector<string>>ans(m.size());
        int index=0;

        for(auto i:m)
        {
            for(auto j:i.second)
            {
                ans[index].push_back(j);
            }
            index++;
        }
        return ans;
    }
};

int main()
{
    vector<string>str={"act","god","cat","dog","tac"};

    ques35 q;
    vector<vector<string>>ans=q.All_Anagrams(str);

    //print
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }

    return 0;
}