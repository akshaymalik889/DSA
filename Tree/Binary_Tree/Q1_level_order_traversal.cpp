#include<iostream>
#include<queue>
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

class ques1
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

    void level_order(Node* root)
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
};

int main()
{
    Node* root=NULL;
    
    ques1  q;
    root=q.buildTree(root);
    cout<<"Tree Implemented..."<<endl;
    q.level_order(root);

    return 0;
}