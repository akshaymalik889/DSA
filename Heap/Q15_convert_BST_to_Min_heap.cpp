#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node
{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    if(val>root->data)
    root->right=buildTree(root->right,val);

    else
    root->left=buildTree(root->left,val);

    return root;
}

void takeinput(Node* &root)
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

void traverse_BST(Node* root)
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

class ques15
{
    private:
   void inorder_BST(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return ;

        inorder_BST(root->left,v);
        v.push_back(root->data);
        inorder_BST(root->right,v);

    }

    void fillpreorder(Node*&root,vector<int>v,int &index)
    {
        if(root==NULL)
        return ;

        root->data=v[index];
        index++;

        fillpreorder(root->left,v,index);
        fillpreorder(root->right,v,index);
    }

    public:
    Node* convert_to_min_heap(Node* root)
    {
        vector<int>v;
        //store inorder of BST
        inorder_BST(root,v);

        int index=0;
        //now just store the inorder in BST in preorder wise
        fillpreorder(root,v,index);

        return root;
    }

};

int main()
{
    Node* root=NULL;
    takeinput(root);
    cout<<"\nTREE CREATED.."<<endl;

    traverse_BST(root);

    ques15 q;

    root=q.convert_to_min_heap(root);

    traverse_BST(root);

    return 0;
}