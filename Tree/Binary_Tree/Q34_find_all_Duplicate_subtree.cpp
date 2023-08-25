#include<iostream>
#include<queue>
#include<unordered_map>
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

class ques34
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

    string solve(Node* root,unordered_map<string,int>&m,vector<Node*>&res)
    {
        if(root==NULL)
        return "$";
        
       string left=solve(root->left,m,res);
       string right=solve(root->right,m,res);
       
       string s= left + "," + right + "," + to_string(root->data);
       
       if(m[s]==1)
       {
           res.push_back(root);
       }
       
       m[s]++;
       return s;
    }
    
    vector<Node*> printAllDups(Node* root)
    {
        unordered_map<string,int>m;
        vector<Node*>res;
    
        solve(root,m,res);
    
        return res;
    }
};

int main()
{
    Node* root=NULL;
    
    ques34 q;

    root=q.buildTree(root);
    //1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1

    cout<<"Tree Created..."<<endl;

    q.levelOrder(root);

    vector<Node*>v=q.printAllDups(root);

    cout<<"root nodes of duplicate subtree...."<<endl;
    for(auto i:v)
    {
        cout<<i->data<<endl;
    }

    return 0;
}