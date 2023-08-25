#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;


class ques6
{

private:

vector<int>nextSmallerElement(vector<int>arr,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {
        while(s.top() != -1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int>prevSmallerElement(vector<int>arr,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=0;i<n;i++)
    {
        while(s.top() != -1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}


int largestRectangleArea(vector<int>&heights,int n)
{
   // int n=heights.size();

    vector<int>next(n);
    next=nextSmallerElement(heights,n);

    vector<int>prev(n);
    prev=prevSmallerElement(heights,n);

    int area=INT_MIN;

    //calculating area

    for(int i=0;i<n;i++)
    {
        int l=heights[i];
        
        if(next[i]==-1)
        next[i]=n;

        int b=next[i]-prev[i]-1;
        int newArea=l*b;

        area=max(newArea,area);
    }
    return area;

}

void traverse(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
 public:

 int maxRectangleArea(vector<vector<int>>&M,int n,int m)
 {
    //STEP 1:Compute area for first row
       int area=largestRectangleArea(M[0],m);
       
       //for remaining rows
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               //row update by adding prev row
               if(M[i][j]!=0)
                M[i][j]=M[i][j] + M[i-1][j];
                else
                M[i][j]=0;
           }
           
           //entire row is updated now
           int newArea=largestRectangleArea(M[i],m);
           area=max(area,newArea);
       }
       return area;
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
    ques6 q;

    int row;
    int col;
    cout<<"enter row"<<endl;
    cin>>row;
    cout<<"enter col"<<endl;
    cin>>col;
    vector<vector<int>>matrix;
    
    for(int i=0;i<row;i++)
    {
        vector<int>rowCol;

        for(int j=0;j<col;j++)
        {
            int val;
            cout<<"enter value:"<<endl;
            cin>>val;
            rowCol.push_back(val);
        }
        matrix.push_back(rowCol);
    }

    q.traverse(matrix);
    cout<<q.maxRectangleArea(matrix,row,col)<<endl;


    return 0;

}