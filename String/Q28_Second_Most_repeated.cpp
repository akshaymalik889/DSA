#include<iostream>
#include<unordered_map>
#include<limits.h>

using namespace std;



class ques28
{
    public:
    string Repeated_String(string arr[],int n)
    {
        unordered_map<string,int>m;
      
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
      
        int largest=INT_MIN;
        int second_L=INT_MIN;
        string second_L_String="";
      
        for(auto i:m)
        {
            if(i.second>largest)
            {
                largest=i.second;
            }
        }
      
      
        for(auto i:m)
        {
            if(i.second<largest && i.second>second_L)
            {
                second_L=i.second;
                second_L_String=i.first;
            }
        }
        return second_L_String;
    }
};


int main()
{
    string arr[]={"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques28 q;
    cout<<q.Repeated_String(arr,n);


    return 0;
}