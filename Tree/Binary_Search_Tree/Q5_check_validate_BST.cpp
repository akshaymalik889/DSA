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

class ques5
{
    public:


    //createing binary tree
    Node* BuildTree(Node* root)
    {
        int data;
        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        return NULL;

        cout<<"enter data for left of "<<data<<endl;
        root->left=BuildTree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=BuildTree(root->right);

        return root; 
    }

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

    //Approach-1
    void inorder_BST(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return ;

        inorder_BST(root->left,v);
        v.push_back(root->data);
        inorder_BST(root->right,v);
    }

    bool isBST_validate_approach_1(Node* root)
    {
        vector<int>v;
        inorder_BST(root,v);

        //check inorder is sorted or not
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
            return false;
        }
        return true;
    }

    //Approach 2

    bool checkValid(Node* root,int min,int max)
    {
        if(root==NULL)
        return true;

        bool cur=root->data>=min && root->data<=max;

        bool l=checkValid(root->left,min,root->data);
        bool r=checkValid(root->right,root->data,max);

        if(cur && l && r)
        return true;

        return false;
    }

    bool isBST_validate_approach_2(Node* root)
    {
        return checkValid(root,INT_MIN,INT_MAX);
    }
};


int main()
{
    Node* root=NULL;

    ques5 q;
    //q.inputData(root);
    //creating binary tree
    root=q.BuildTree(root);
    cout<<"Tree Created.."<<endl;
    //10 5 -1 -1 12 -1 -1
    //10 12 -1 -1 15 -1 -1

    q.levelOrder(root);

    cout<<q.isBST_validate_approach_1(root)<<endl;
    cout<<q.isBST_validate_approach_2(root);
    

    return 0;
}