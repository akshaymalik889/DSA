#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node
{
    public:
    int data;
    int row; //row
    int col; //col
    
    Node(int data,int row,int col)
    {
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

//comperator declare
class compare
{
    public:
    bool operator()( Node*a,Node* b)
    {
      return a->data > b->data;
    }
};

class ques6
{
    public:

    vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
  {
    // Write your code here. 
    priority_queue<Node* ,vector<Node*>,compare>pq;
    //here compare is comperator
    
    //step -1  //insert all array first elment
    for(int i=0;i<k;i++)
    {
        Node* temp=new Node(arr[i][0],i,0);  
        pq.push(temp);
    }
    
    //step -2 //
    vector<int>ans;
    while(pq.size()>0)
    {
        //save top value
        Node* temp=pq.top();
        
        //store top in vector
        ans.push_back(temp->data);
            pq.pop();
        
        //now insert next element of same array
        int row=temp->row;
        int col=temp->col;
        
        //checking next element exist in array
        if(col+1 < arr[row].size())
        {
            //now we store next element  in min heap
            Node*next= new Node(arr[row][col+1],row,col+1);
            pq.push(next);
        }
    }
    return ans;
  }

};


int main()
{
    ques6 q;
    vector<vector<int>>v
    {
        {1, 5, 9},
        {45, 90},
        {2,6,78,100,234}
    };

    vector<int>ans=q.mergeKSortedArrays(v,v.size());
    for(auto i:ans)
    cout<<i<<" ";
}