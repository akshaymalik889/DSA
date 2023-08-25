#include<iostream>
#include<queue>
#include<limits.h>
#include<vector>

using namespace std;

class Node
{
    public:
    int data;
    int row;
    int col;
    
    Node(int d,int r,int c)
    {
        data=d;
        row=r;
        col=c;
    }
};

class compare
{
    public:
    bool operator()(Node*a,Node*b)
    {
        return a->data > b->data;
    }
};

class ques11
{
    public:

    int kSorted(vector<vector<int>> &a, int k, int n) {
   int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<Node*,vector<Node*>,compare>pq;
    
    //step 1 -> push first element in heap and also finding max and min values
    for(int i=0;i<k;i++)
    {
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        Node*temp=new Node(element,i,0);
        pq.push(temp);
    }
    
    //finding range and update if new range comes
    int start=mini,end=maxi;
    
    while(!pq.empty())
    {
        //finding mini
        Node*temp=pq.top();
        pq.pop();
        mini=temp->data;
        
        //update range
        if(maxi-mini < end-start)
        {
            start=mini;
            end=maxi;
        }
        
        //check min element list next element exist or not-> if exist then update max
        if(temp->col+1 < n)
        {
         maxi=max(maxi,a[temp->row][temp->col+1]);
            Node*next= new Node(a[temp->row][temp->col+1],temp->row,temp->col+1);
            pq.push(next);
        }
        else
            break;
    }
    
    return (end-start+1);
    
}

};

int main()
{
    vector<vector<int>>v
    {
        {1,10,11},
        {2,3,20},
        {5,6,12}
    };

    ques11 q;

    cout<<q.kSorted(v,v.size(),v[0].size());

}