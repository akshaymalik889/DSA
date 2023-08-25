#include<iostream>
#include<queue>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->left==NULL;
        this->right=NULL;
        this->next=NULL;
    }
};

class ques16
{
    public:

    Node* buildTree(Node* root,int d)
    {
        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }

        else if(d<root->data)
        {
            root->left=buildTree(root->left,d);
        }
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

    int getCount(Node *root, int l, int h)
    {
        if(root==NULL)
        return 0;
      
        if(root->data >=l && root->data <=h)
        return 1 + getCount(root->left,l,h) + getCount(root->right,l,h);
      
        else if(root->data < l)
        return getCount(root->right,l,h);
      
        else
        return getCount(root->left,l,h);
    }

};


int main()
{

    Node* root=NULL;

    ques16 q;
    q.inputTree(root);
    cout<<"Tree  Created..."<<endl;
    //10 5 50 2 40 100 1 90 110 0 -1

    
    q.levelOrder(root);

    cout<<q.getCount(root,5,45);

    return 0;
}