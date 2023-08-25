#include<iostream>
#include<vector>
using namespace std;


class ques26
{
    public:
    string longest_common_prefix(vector<string>&arr)
    {
        string ans="";

        for(int i=0;i<arr[0].length();i++)
        {
            char ch=arr[0][i];
            bool ismatch=true;

            //for traverse over other strings
            for(int j=1;j<arr.size();j++)
            {
                //not match
                if(arr[j].length()<i || ch!=arr[j][i])
                {
                    ismatch=false;
                    break;
                }
            }

            if(ismatch==false)
            {
                break;
            }
            else
            ans.push_back(ch);
        }
        return ans;
    }
};


int main()
{
    vector<string>arr={"flower","flow","flight"};

    ques26 q;
    cout<<q.longest_common_prefix(arr);


    return 0;
}