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

class ques10
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

    void inorder(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return ;

        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    Node* solve(int start,int end,vector<int>v)
    {
        if(start>end)
        return NULL;

        //finding mid
        int mid=start+((end-start)/2);

        //make node for mid
        Node* newRoot=new Node(v[mid]);

        newRoot->left=solve(start,mid-1,v);
        newRoot->right=solve(mid+1,end,v);

        return newRoot;
    }

    Node* normal_to_balanced(Node* root)
    {
        vector<int>v;

        inorder(root,v);

        root=solve(0,v.size()-1,v);
        return root;
    }

};


int main()
{
    Node* root=NULL;

    ques10 q;
    q.inputData(root);
    cout<<"Tree Created.."<<endl;
    //4 3 2 1 -1
    //30 20 10 -1

    q.levelOrder(root);

    root=q.normal_to_balanced(root);
    
    q.levelOrder(root);

    return 0;
}