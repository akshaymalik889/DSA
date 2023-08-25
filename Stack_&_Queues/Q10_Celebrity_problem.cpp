#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class ques10
{

    public:
    int celebrity(vector<vector<int>>&M,int n)
    {
        stack<int>s;
        //step=1 pushh all elemnets in stack
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }

        //step 2 :get top 2 elements and compare them
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();

            int b=s.top();
            s.pop();

            //check they know or now know
            if(M[a][b])
            s.push(b);  //IT MEANS A KNOW B  so A NOT CELEBRITY 

            else
            s.push(a);  //IT MEANS B KNOW A  so B NOT CELEBRITY 
        }

        //step 3:now only single elment left
        int candidate=s.top();

        //ROW check
       int zerocount=0;
        for(int i=0;i<n;i++)
        {
            if(M[candidate][i]==0)
            zerocount++;
        }
        //check all zeroes
        if(zerocount!=n)
        return -1;

        //COL check
        int onecount=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][candidate]==1)
            onecount++;
        }
        //check all zeroes
        if(onecount!=n-1)
        return -1;

        //now both zerocount and onecount are satisfied celebrity condition
        return candidate;

    }

    void traverse(vector<vector<int>>&v)
    {
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

};


int main()
{
    ques10 q;

    int n;
    cout<<"enter row and col"<<endl;
    cin>>n;
    vector<vector<int>>matrix;
    
    for(int i=0;i<n;i++)
    {
        vector<int>rowCol;

        for(int j=0;j<n;j++)
        {
            int val;
            cout<<"enter value:"<<endl;
            cin>>val;
            rowCol.push_back(val);
        }
        matrix.push_back(rowCol);
    }

    q.traverse(matrix);

    cout<<q.celebrity(matrix,n)<<endl;



    return 0;

}
