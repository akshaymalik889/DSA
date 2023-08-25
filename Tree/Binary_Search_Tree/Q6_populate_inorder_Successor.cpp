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

class ques6
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
                if(temp->next==NULL)
                cout<<"NULL ";
                else
                cout<<temp->next->data<<" ";


                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    void solve(Node* root,Node* &prev)
    {
        if(root==NULL)
        return ;
        
        solve(root->left,prev);
        
        if(prev!=NULL)
        prev->next=root;
        
        prev=root;
        
        solve(root->right,prev);
    }

    void populateNext(Node *root)
    {
        Node* prev=NULL;
        solve(root,prev);
    }

};


int main()
{

    Node* root=NULL;

    ques6 q;
    q.inputTree(root);
    cout<<"Tree Created..."<<endl;
    //10 8 3 12 -1

    q.levelOrder(root);
    q.populateNext(root);

    cout<<"Node with inorder Successor..."<<endl;
    q.levelOrder(root);


    return 0;
}