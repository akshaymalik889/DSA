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
    Node* buildTree(Node* root)
    {
        int data;
        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        {
            return NULL;
        }

        cout<<"enter data for left of "<<data<<endl;
        root->left=buildTree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=buildTree(root->right);

        return root;
    }

    void levelOrder(Node * root)
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

    //check sum tree or not
    pair<bool,int>isSumtree(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int>p;
            p.first=true;
            p.second=0;
            
            return p;
        }
        
        //avoid leaf nodes
        if(root->left==NULL && root->right==NULL)
        {
            pair<bool,int>p;
            p.first=true;
            p.second=root->data;
            
            return p;
        }
        
        
        pair<bool,int>left=isSumtree(root->left);
        pair<bool,int>right=isSumtree(root->right);
        
        //check left subtree
        bool op1=left.first;
        
        //check right subtree
        bool op2=right.first;
        
        //check current Node
        bool op3=root->data==left.second + right.second;
        
        pair<bool,int>ans;
        
        if(op1 && op2 && op3)
        {
            ans.first=true;
            ans.second=root->data+left.second+right.second;
        }
        else
        {
            ans.first=false;
            ans.second=root->data+left.second+right.second;
        }
        return ans;
        
    }

    bool isSumTree(Node* root)
    {
        return isSumtree(root).first;
         
    }


};

int main()
{
    Node* root=NULL;

    ques22 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1
    //10 20 10 -1 -1 10 -1 -1 30 -1 -1
    //3 1 -1 -1 2 -1 -1

    q.levelOrder(root); 

    cout<<q.isSumTree(root);
    return 0;

}