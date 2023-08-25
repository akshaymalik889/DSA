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

class ques0
{
    public:

    Node* buildTree(Node* root,int d)
    {
        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }

        else if(d > root->data)
        root->right=buildTree(root->right,d);

        else
        root->left=buildTree(root->left,d);

        return root;
    }

    void takeInput(Node* &root)
    {
        int data;

        cout<<"enter data for BST:"<<endl;
        cin>>data;

        while(data!=-1)
        {
            root=buildTree(root,data);
            cin>>data;
        }
    }

    void levelOrder(Node*root)
    {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node*temp=q.front();
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

    ques0 q;

    q.takeInput(root);
    cout<<"Tree Created..."<<endl;
    //10 8 21 7 27 5 4 3 -1

    q.levelOrder(root);


    return 0;
}
