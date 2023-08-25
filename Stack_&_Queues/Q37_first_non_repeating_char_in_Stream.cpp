#include<iostream>
#include<queue>
#include<map>
using namespace std;

class question 
{
    public:

    string non_repeating(string &str)
    {
        map<char,int>m;
        string ans="";
        queue<int>q;

        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];

            //INCREASE COUNT
            m[ch]++;

            //PUSH IN QUEUE
            q.push(ch);

            while(!q.empty())
            {
                if(m[q.front()]>1)
                {
                    //REPEATING CHARACTER
                    q.pop();
                }

                else
                {
                    //NON REPEATING CHARATER
                    ans.push_back(q.front());
                    break;
                }
            }

            if(q.empty())
            ans.push_back('#');
        }
        return ans;

        
    }

    void traverse(string str)
    {
        for(int i=0;i<str.length();i++)
        {
            cout<<str[i]<<" ";
        }
        cout<<endl;
    }

};


int main()
{
    question ob1;

    string str="aabc";

    ob1.traverse(str);
    string ans=ob1.non_repeating(str);
    ob1.traverse(ans);


    return 0;
}