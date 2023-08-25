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
        this->left==NULL;
        this->right=NULL;
    }
};

class ques32
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
                cout<<temp->data;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
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

    int solve(Node* root,int val)
    {
        if(root==NULL)
        return 0;

        if(root->data==val)
        return 1;

        int a=solve(root->left,val);
        int b=solve(root->right,val);

        if(a==0 && b==0)
        return 0;

        else
        return a+b+1;
    }

    int minDistance(Node* root,int a ,int b)
    {
        //find common ancestor
        Node* lca=LCA(root,a,b);

        //now find distance till a
        int x=solve(lca,a);
        cout<<"x="<<x<<endl;

        //find distance till b
        int y=solve(lca,b);
        cout<<"y="<<y<<endl;

        //return sum of x+y
        return x+y-2;
    }  
};

int main()
{
    Node* root=NULL;
    
    ques32 q;

    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1

    q.levelOrder(root);

    cout<<q.minDistance(root,4,6);

    return 0;
}