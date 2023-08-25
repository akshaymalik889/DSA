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

class ques28
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

    int solve(Node* root,int &maxSum)
    {
        if(root==NULL)
        return 0;

        // else if(root->left==NULL && root->right==NULL)
        // return root->data;

        int l=solve(root->left,maxSum);
        int r=solve(root->right,maxSum);

        if(l+r+root->data > maxSum)
        {
            maxSum=l+r+root->data;
        }
        return l+r+root->data;
    }

    int largestSubtree_Sum(Node* root)
    {
        int maxSum=INT_MIN;

        solve(root,maxSum);
        return maxSum;
    }

    
};

int main()
{
    Node* root=NULL;

    ques28 q;
    root=q.buildTree(root);

    cout<<"\nTREE Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 -2 4 -1 -1 5 -1 -1 3 -6 -1 -1 2 -1 -1

    q.levelOrder(root);

    cout<<q.largestSubtree_Sum(root);

    return 0;
}