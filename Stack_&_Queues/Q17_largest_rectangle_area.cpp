#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

class ques17{

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


public:
int largestRectangle(vector<int>&heights)
{
    int n=heights.size();

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



};


int main()
{
    vector<int>heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    ques17 q;

    q.traverse(heights);
    cout<<q.largestRectangle(heights)<<endl;

    return 0;
}