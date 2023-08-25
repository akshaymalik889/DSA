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

class ques8
{
    public:
    Node* buildTree(Node* root,int d)
    {   
        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }
        else if(d < root->data)
        root->left=buildTree(root->left,d);

        else
        root->right=buildTree(root->right,d);

        return root;
    }



    void inputData(Node* &root)
    {
        int data;
        cout<<"enter data for BST.."<<endl;
        cin>>data;

        while(data!=-1)
        {
            root=buildTree(root,data);
            cin>>data;
        }
    }

    void levelOrder(Node* root)
    {
        if(root==NULL)
        return ;

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

    Node* solve(vector<int>&pre,int mini,int maxi,int &i)
    {
        if(i>=pre.size())
        return NULL;
        
        //NOT lie in range
        if(pre[i] < mini || pre[i] >maxi)
        return NULL;

        //lie in range
        //node create

        Node* newRoot=new Node(pre[i]);

        i++;

        newRoot->left=solve(pre,mini,newRoot->data,i);
        newRoot->right=solve(pre,newRoot->data,maxi,i);

        return newRoot;
    }

    Node* preorder_TO_BST(vector<int>pre)
    {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;

        Node* root=solve(pre,mini,maxi,i);
        
        return root;
    }

};


int main()
{
    Node* root=NULL;

    ques8 q;
    // q.inputData(root);
    // cout<<"Tree Created.."<<endl;
    // //10 5 1 7 40 50 -1

    vector<int>pre;
    pre.push_back(10);
    pre.push_back(5);
    pre.push_back(1);
    pre.push_back(7);
    pre.push_back(40);
    pre.push_back(50);

    q.levelOrder(root);

    root=q.preorder_TO_BST(pre);
    q.levelOrder(root);
    

    return 0;
}