#include<iostream>
#include<unordered_map>
using namespace std;

class ques39
{
    public:
    int Customer_Not_Computer(string s,int n)
    {
        unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
        m[s[i]]=0;
        
        int occupied=0;
        int didnotget=0;   //ans

        for(int i=0;i<s.length();i++)
        {
            //customer visited first time  && computer unoccupied
            if(m[s[i]]==0 && occupied<n)
            {
                m[s[i]]=1;
                occupied++;
            }


            // person is leaving now
            else if(m[s[i]]==1 && occupied<=n)
            {
                occupied--;

                //person lefft so visited =0
                m[s[i]]=0;
            }

            else
            didnotget++;
        }
        //divide by 2 bcoz we counted he duplicates there
        return didnotget/2;
    }
};



int main()
{
    string s="GACCBDDBAGEE";
    int n=3;

    ques39 q;
    cout<<q.Customer_Not_Computer(s,n);

    return 0;
}