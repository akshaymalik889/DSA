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

class info
{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;  
};

class ques21
{
    public:
    Node* buildTree(Node*root)
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
                cout<<temp->data<<" ";

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    info solve(Node* root,int &ans)
    {
        //base case
        if(root==NULL)
        return {INT_MIN,INT_MAX,true,0};
        
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        
        info curNode;
        
        curNode.size=left.size+right.size+1;
        curNode.maxi=max(root->data,right.maxi);
        curNode.mini=min(root->data,left.mini);
        
        if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini) )
        curNode.isBST=true;
        else
        curNode.isBST=false;
        
        //update answer
        if(curNode.isBST)
        {
            ans=max(ans,curNode.size);
        }
        return curNode;
    }

    int largestBST(Node* root) 
    {
        int maxSize=0;
        info temp=solve(root,maxSize);
        return maxSize;
    }
};

int main()
{
    Node* root=NULL;
    
    ques21 q;
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;
    //1 4 6 -1 -1 8 -1 -1 4 -1 -1

    q.levelOrder(root);

    cout<<q.largestBST(root);

    return 0;
}