#include<iostream>
#include<vector>
using namespace std;

class ques42
{
    private:
    void solve(vector<vector<string>>s,string ans,int row)
    {
        //BASE CASE: Reaches Last row then we print
        if(row==s.size())
        {
            cout<<ans<<endl;
            return ;
        }

        for(int i=0;i<s[row].size();i++)
        {
            if(s[row][i]!= "")
            solve(s,ans+ " " + s[row][i],row+1);
        }
    }

    public:
    void print_Sentences(vector<vector<string>>s)
    {
        string ans="";
        solve(s,ans,0);
    }
};

int main()
{   
    vector<vector<string>> s
    {
        {"you","we"},
        {"have","are"},
        {"sleep","eat","drink"}
    };

    ques42 q;
    q.print_Sentences(s);

    return 0;
}