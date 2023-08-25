#include<iostream>
using namespace std;

class ques19
{
    public:
    string numeric_Sequence(string word)
    {

        string str[]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666",
        "7","77","777","7777","8","88","888","9","99","999","9999"};

        string ans="";

        for(int i=0;i<word.length();i++)
        {
            //if space
            if(word[i]==' ')
            ans=ans+'0';
            
            else
            {
                int j=word[i]-'A';
                ans=ans+str[j];
            }
        }
        return ans;

    }
};

int main()
{
    string word="GEEKSFORGEEKS";

    ques19 q;
    cout<<q.numeric_Sequence(word);

    return 0;
}