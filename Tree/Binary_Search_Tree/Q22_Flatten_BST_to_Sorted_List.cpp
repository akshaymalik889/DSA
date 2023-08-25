#include<iostream>
#include<queue>
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

class ques22
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

    void inputTree(Node* &root)
    {
        int data;
        cout<<"enter data for BST..."<<endl;
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

    void inorder(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return ;

        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

   Node* flatten_BST(Node* root)
    {
        vector<int>v;
        //store inorder in vector
        inorder(root,v);

        //make new node of first value

        Node* newRoot=new Node(v[0]);

        //make a pointer to point first node
        Node* temp=newRoot;

        //traverse vector
        for(int i=1;i<v.size();i++)
        {
            Node* newNode=new Node(v[i]);
            temp->left=NULL;
            temp->right=newNode;
            temp=newNode;
        }

        //make last node right NULL && left NULL
        temp->right=NULL;
        temp->left=NULL;

        return newRoot;

    }

    void inorder_nodes(Node* root,vector<Node*>&v)
    {
        if(root==NULL)
        return ;

        inorder_nodes(root->left,v);
        v.push_back(root);
        inorder_nodes(root->right,v);
    }

    Node* flatten_BST_Approach_1(Node* root)
    {
        vector<Node*>v;
        inorder_nodes(root,v);
        // for(auto i:v)
        // {
        //     cout<<i->data<<" ";
        // }
        // cout<<endl;

        int i=0;

        Node* newRoot=v[0];
        

        for(i=0;i<v.size()-1;i++)
        {
            v[i]->left=NULL;
            v[i]->right=v[i+1];
        }

        v[i]->left=NULL;
        v[i]->right=NULL;
        
        return newRoot;
    }

    
};


int main()
{
    Node* root=NULL;

    ques22 q;
    q.inputTree(root);
    cout<<"Tree Created..."<<endl;
    //5 3 7 2 4 6 8 -1

    q.levelOrder(root);

    root=q.flatten_BST_Approach_1(root);

    q.levelOrder(root);

    return 0;
    
}