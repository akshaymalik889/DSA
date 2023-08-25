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

class ques29
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

    pair<int,int>solve(Node* root)
    {
        if(root==NULL)
        {
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
         
         pair<int,int>res;
         
         res.first=root->data+left.second+right.second;
         res.second=max(left.first,left.second)+max(right.first,right.second);
         
         return res;
    }

    int max_Sum_adjacent(Node* root)
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }

    
};

int main()
{
    Node* root=NULL;

    ques29 q;
    root=q.buildTree(root);

    cout<<"\nTREE Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 -2 4 -1 -1 5 -1 -1 3 -6 -1 -1 2 -1 -1
    //1 2 1 -1 -1 -1 3 4 -1 -1 5 -1 -1
    //10 1 2 1 -1 -1 -1 3 4 -1 -1 5 -1 -1 -1

    q.levelOrder(root);

    cout<<q.max_Sum_adjacent(root);

    return 0;
}