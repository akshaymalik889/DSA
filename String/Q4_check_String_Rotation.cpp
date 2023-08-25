#include<iostream>
using namespace std;


class ques4
{
    public:
    bool string_rotation(string str1,string str2)
    {
        if(str1.length()!=str2.length())
        return false;

        str1=str1+str1;
        if(str1.find(str2)!=string::npos)
        {
            return true;
        }
        else
        return false;
    }
};


int main()
{

    string str1="ABACD";
    string str2="CDABA";

    ques4 q;
    cout<<q.string_rotation(str1,str2);

    return 0;
}