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

class ques26
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

    void solve(Node* root,int sum,int height,int &maxSum,int &maxHeight)
    {
        if(root==NULL)
        {
            if(height>=maxHeight)
            {
                maxHeight=height;
                maxSum=sum;
            }
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            sum=sum+root->data;
            height=height+1;
            if(height>=maxHeight)
            {
                maxHeight=height;
                maxSum=sum;
            }
            return;
        }

        sum=sum+root->data;
        height=height+1;

        solve(root->left,sum,height,maxSum,maxHeight);
        solve(root->right,sum,height,maxSum,maxHeight);


    }

    int sum_longest_path(Node* root)
    {
        int sum=0;
        int height=0;

        int maxSum=INT_MIN;
        int maxHeight=0;

        solve(root,sum,height,maxSum,maxHeight);
        return maxSum;
    }

};

int main()
{
    Node* root=NULL;

    ques26 q;
    root=q.buildTree(root);

    cout<<"\nTREE Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    q.levelOrder(root);

    cout<<q.sum_longest_path(root);
    

    return 0;
}