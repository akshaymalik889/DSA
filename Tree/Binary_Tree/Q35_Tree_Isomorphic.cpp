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

class ques35
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
        cout<<endl;
    }

    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL && root2==NULL)
        return true;
        
        if(root1==NULL || root2==NULL)
        return false;
        
        if(root1->data !=root2->data)
        return false;
        
        bool a=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
        
        bool b=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
    
        return a || b;
        
    }
    
};

int main()
{
    Node* root1=NULL;
    Node* root2=NULL;
    
    ques35 q;

    root1=q.buildTree(root1);
    cout<<"Tree 1 Created..."<<endl;
    //1 2 4 -1 -1 -1 3 -1 -1
    //1 2 4 -1 -1 -1 3 -1 -1


    root2=q.buildTree(root2);
    cout<<"Tree 2 Created..."<<endl;
    //1 3 4 -1 -1 -1 2 -1 -1
    //1 3 -1 -1 2 -1 4 -1 -1

    q.levelOrder(root1);
    q.levelOrder(root2);

    cout<<q.isIsomorphic(root1,root2);


    return 0;
}