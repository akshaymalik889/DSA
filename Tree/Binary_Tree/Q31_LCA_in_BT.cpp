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

class ques31
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

    Node* LCA(Node* root,int n1,int n2)
    {
        if(root==NULL)
        return NULL;

        if(root->data==n1 || root->data==n2)
        return root;

        Node* l=LCA(root->left,n1,n2);
        Node* r=LCA(root->right,n1,n2);

         if(l!=NULL && r!=NULL)
        return root;
        
        else if(l!=NULL && r==NULL)
        return l;

        else if(l==NULL && r!=NULL)
        return r;

        else
        return NULL;
    }

    
};

int main()
{
    Node* root=NULL;

    ques31 q;
    root=q.buildTree(root);

    cout<<"\nTREE Created..."<<endl;

   
    //5 2 3 -1 -1 4 -1 -1 -1


    q.levelOrder(root);

    cout<<q.LCA(root,3,4)->data;

    return 0;
}