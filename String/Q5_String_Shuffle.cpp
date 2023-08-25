#include<iostream>
using namespace std;

class ques5
{
    public:
    bool stringShuffle(string str1,string str2,string res)
    {
        //check length first
        int l1=str1.length();
        int l2=str2.length();
        int resl=res.length();

        if(l1+l2!=resl)
        return false;

        int i=0,j=0,k=0;

        while(k<resl)
        {
            if(i<l1 && str1[i]==res[k])
            i++;
            else if(j<l2 && str2[j]==res[k])
            j++;
            else
            return false;

            k++;
        }
        return true;
    }
};


int main()
{
    string str1="XY";
    string str2="12";
    string res="X1Y2";

    ques5 q;
    cout<<q.stringShuffle(str1,str2,res);

    return 0;
}