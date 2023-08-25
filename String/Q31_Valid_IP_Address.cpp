#include<iostream>
#include<vector>
using namespace std;

class ques31
{
    private:

    bool isValid(string str)
    {
        if(str.size()>3||str.size()==0)
        return false;
   
        if(str.size()>1 && str[0]=='0')
        return false;
   
        // using stoi to convert string to integer 
        if(str.size() && stoi(str)>255)
        return false;

        return true;
    }
    void solve(string s,int i,int dots,string ans,vector<string>&v)
    {
        // we have to place 3 dots in the string to make 4 partitions
        if(dots==3)
        {
            // pushing last partition after checking its validity
            if(isValid(s.substr(i)))
            v.push_back(ans+s.substr(i));
        
            return;
        }
	
        // placing the dot at every valid position
	
        for(int j=i; j<s.size() ;j++)
        {
	        if( isValid(s.substr(i, j-i+1)))
	        {
		        ans.push_back(s[j]);
		        ans.push_back('.');

		        solve(s,j+1,dots+1, ans, v);

	            // removing the dot after calling recur function 

	            // note that we don't remove the last digit that was placed in temp string 
                //as we just have to change positions of dots only and not digits in string
		        ans.pop_back();
            }
        }
        return;
    }

    public:
    vector<string>valid_ip(string s)
    {
        vector<string>v;

        if(s.size()<4) 
        return v;
    
        solve(s,0, 0, "", v);
        return v;
    }
};


int main()
{
    string s="25525511135";

    ques31 q;
    vector<string>ans=q.valid_ip(s);

    //print
    for(auto i:ans)
    cout<<i<<endl;


    return 0;

}