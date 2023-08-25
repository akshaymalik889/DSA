#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class ques10
{

    private:
    void solve(string s,vector<string>&ans,int i)
    {
        //base case
        if(i>=s.length())
        {
            ans.push_back(s);
            return;
        }

        //set for store only unique elments it should be int
        unordered_set<int>st;

        //fixed one position and traverse till last
        for(int j=i;j<s.length();j++)
        {
            //if already present then skip so no recursion call
            if(st.count(s[j]))
            continue;

            st.insert(s[j]);

            //swap to move i
            swap(s[j],s[i]);

            //recursion
            solve(s,ans,i+1);

            //backtrack
            swap(s[j],s[i]);
        }
    }

    public:

    //Approach -> Recursion
    vector<string>unique_permutations(string s)
    {
        vector<string>ans;
        solve(s,ans,0);
        //we do sort for lexiographically order
        sort(ans.begin(),ans.end());

        return ans;
    }
};

int main()
{
    string s="AABC";
    ques10 q;
    vector<string>ans=q.unique_permutations(s);
    
    //print result
    for(auto i:ans)
    cout<<i<<" ";


    return 0;
}