#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;


class ques36
{
    public:
    int minimum_Sum_strings(string s,int k)
    {

        unordered_map<char,int>m;
        
        //store frequency of characters in map
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        //take  max heap to get max value at top
        priority_queue<int>pq;
        
        //insert in heap
        for(auto i:m)
        {
            pq.push(i.second);
        }
        
        //decrease maximum values by k times        
        while(k!=0)
        {
            int val=pq.top();
            pq.pop();
            val--;
            pq.push(val);
            k--;
        }
        
        //finding answer
        int sum=0;
        while(!pq.empty())
        {
            int val=pq.top();
            pq.pop();
            
            sum=sum+ (val*val);
        }
        return sum;
    }
};


int main()
{
    string s="aabcbcbcabcc";
    int k=3;

    ques36 q;
    cout<<q.minimum_Sum_strings(s,k);

    return 0;
}