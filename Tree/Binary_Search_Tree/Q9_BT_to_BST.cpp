#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
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


class ques9
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
                cout<<temp->data<<" ";

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    void inorder_Tree(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return;
        
        inorder_Tree(root->left,v);
        
        v.push_back(root->data);
        
        inorder_Tree(root->right,v);
    }
    
    void inorder_BST(Node* root,vector<int>v,int &i)
    {
        if(root==NULL)
        return;
        
        inorder_BST(root->left,v,i);
        
        root->data=v[i];
        i++;
        
        inorder_BST(root->right,v,i);
    }

    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        inorder_Tree(root,v);
        
        sort(v.begin(),v.end());
        
        int i=0;
        inorder_BST(root,v,i);
        
        return root;
    }
};


int main()
{
    Node* root=NULL;

    ques9 q;
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;
    //1 2 4 -1 -1 -1 3 -1 -1

    q.levelOrder(root);
    q.binaryTreeToBST(root);

    q.levelOrder(root);

    return 0;
}