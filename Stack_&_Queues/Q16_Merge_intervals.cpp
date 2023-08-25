#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class ques14
{
    public:

    //Approch-1 with using stack
    void merger_Intervals_ap_1(vector<vector<int> >intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> >ans;
        
        stack<pair<int,int> >s;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(s.empty())
                s.push(make_pair(intervals[i][0],intervals[i][1]));
            
            else
            {
                pair<int,int>p;
                p=s.top();
                
                if(p.second>=intervals[i][0])
                {
                    s.pop();
                    if(p.second<=intervals[i][1])
                    s.push(make_pair(p.first,intervals[i][1]));
                    else
                        s.push(make_pair(p.first,p.second));
                }
                else
                    s.push(make_pair(intervals[i][0],intervals[i][1]));
            }
        }
        
       while(!s.empty())
       {
           vector<int>temp;
           pair<int,int>p=s.top();
           s.pop();
           temp.push_back(p.first);
           temp.push_back(p.second);
           
           ans.push_back(temp);
       }
        
        for(auto i:ans)
        {
            cout<<i[0]<<" "<<i[1]<<endl;
        }
    }

    //Approach -2 -> without using extra space
    void merger_Intervals_ap_2(vector<vector<int> >intervals)
    {
        sort(intervals.begin(),intervals.end());
        
       int index=0;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[index][1]>=intervals[i][0])
            {
                intervals[index][1]=max(intervals[index][1],intervals[i][1]);
            }
            else
            {
                index++;
                intervals[index]=intervals[i];
            }
        }

        for(int i=0;i<=index;i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
    }

};


int main()
{
    vector<vector<int>>intervals
    { 
        {1,3},{2,6},{8,10},{15,18}
    };
    
    ques14 q;
   // q.merger_Intervals_ap_1(intervals);
    q.merger_Intervals_ap_2(intervals);


    return 0;
}