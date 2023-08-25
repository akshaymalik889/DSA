#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class ques30
{
    public:
    Node* buildTree(Node* root)
    {
        int data;
        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        return NULL;

        cout<<"enter data for left of "<<data<<endl;
        root->left=buildTree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=buildTree(root->right);

        return root;
    }

    void levelOrder(Node* root)
    {
        
        if(root==NULL)
        return;

        queue<Node*>q;
        q.push(root);
        q.push(NULL);
       

        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                cout<<endl;

                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                cout<<temp->data;
                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
        cout<<endl;
        return;
    }

    //count paths

    void solve(Node* root,int k,int &count,vector<int>v)
    {
        if(root==NULL)
        return;
        //push starting node 
        v.push_back(root->data);

        //left call
        solve(root->left,k,count,v);
        //right call
        solve(root->right,k,count,v);
        
        //check for k sum
        int size=v.size();
        int sum=0;
        for(int i=size-1;i>=0;i--)
        {
            sum=sum+v[i];
            if(sum==k)
            {
                count++;
                for(int j=i;j<v.size();j++)
                {
                    cout<<v[j]<<" ";
                }
                cout<<endl;

            }
            
        }
        v.pop_back();
    }

    int Ksum(Node* root,int k)
    {
        vector<int>v;
        int count=0;

        solve(root,k,count,v);
        return count;
    }
    
};

int main()
{
    Node* root=NULL;

    ques30 q;
    root=q.buildTree(root);

    cout<<"\nTREE Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 3 2 -1 -1 1 1 -1 -1 -1 0 4 1 -1 -1 2 -1 -1 5 -1 6 -1 -1

    

    q.levelOrder(root);
    
    cout<<q.Ksum(root,5)<<endl;




    return 0;
}