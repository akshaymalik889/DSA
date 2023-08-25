#include<iostream>
using namespace std;

class ques7
{
    public:
    //Approach -Odd Even
    string longestSubstring(string str)
    {
        int start=0;
        int end=1;

        for(int i=1;i<str.length();i++)
        {
            //odd
            int left=i-1;
            int right=i+1;

            while(left>=0 && right <str.length() && str[left] == str[right])
            {
                if( (right-left +1) > end)
                {
                    start=left;
                    end=right-left+1;
                }

                left--;
                right++;
            }
            


            //EVEN
            left=i-1;
            right=i;

            while(left>=0 && right <str.length() && str[left] == str[right])
            {
               if( (right-left +1) > end)
                {
                    start=left;
                    end=right-left+1;
                }
                
                left--;
                right++;
            }
        }

        //storing string 

        string ans="";
        for(int i=start;i<=start+end-1;i++)
        {
            ans.push_back(str[i]);
        }

        return ans;

    }
};

int main()
{
    string str="bbbab";

    ques7 q;
    string ans=q.longestSubstring(str);
    cout<<ans;

    return 0;
}