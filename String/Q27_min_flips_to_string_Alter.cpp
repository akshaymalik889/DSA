#include<iostream>
using namespace std;


class ques27
{
    public:
    int min_flips(string str)
    {

        //NOTE ->here even odd based on index value
        
        //case 1 ->even-0,odd-1
        int c1=0;
    
        //case 2 ->even-1,odd-0
        int c2=0;
    
        for(int i=0;i<str.length();i++)
        {
            //even
            if(i%2==0)
            {
                if(str[i]=='1')
                c1++;
                else
                c2++;
            }
            else //odd
            {
                if(str[i]=='0')
                c1++;
                else
                c2++;
            }
        
        }
        return min(c1,c2);
    }
};

int main()
{
    string str="0001010111";

    ques27 q;
    cout<<q.min_flips(str);

    return 0;
}