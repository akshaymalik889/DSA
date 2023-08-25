#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class question
{
    public:

    //Approach-1
    vector<int> firstNegative_Ap_1(int arr[],int n,int k)
    {
        vector<int>v;

        for(int i=0;i<=n-k;i++)
        {
            int ans=0;
            int flag=0;
            for(int j=i;j<i+k;j++)
            {
                
                if(arr[j]<0)
                {
                    flag=1;
                    ans=arr[j];
                    break;
                }

            }
            if(flag==1)
            v.push_back(ans);
            else
            v.push_back(0);
        }
        return v;
    }


//APPROACH 2 USING QUEUE FOR MORE OPTOMISED
    vector<int>firstNegative_AP_2(int arr[],int n,int k)
    {
        vector<int>v;
        queue<int>q;
        
        //process first k window size elements
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
            q.push(i);
        }
        //process ans for first window
        if(q.size()>0)
        {
            v.push_back(arr[q.front()]);
        }
        else
        v.push_back(0);

        //PROCESS REMAINING ELEMENTS NOW

        for(int i=k;i<n;i++)
        {
            //delete index from queue of prev window
            if(!q.empty() && i-q.front()>=k)
            q.pop();

            //now add cur element of window in queue if it is a negative no.
            if(arr[i]<0)
            q.push(i);

            //now store ans in vector
            if(q.size()>0)
            {
                v.push_back(arr[q.front()]);
            }
            else
            v.push_back(0);
        }
        return v;
    }

};



int main()
{
    question q;

    int arr[]={-8,2,3,-6,10};
    int n=5;
    int k=2;
    
    //vector<int>v=q.firstNegative_Ap_1(arr,n,k);
    vector<int>v=q.firstNegative_AP_2(arr,n,k);

    //print
    for(auto i:v)
    cout<<i<<" ";
    
    return 0;
}