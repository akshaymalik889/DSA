#include<iostream>
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

class ques13
{
    private:
    int countNodes(Node* root)
    {
        if(root==NULL)
        return 0;

        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return left+right+1;
    }

    bool isCBT(Node* root,int index,int count)
    {
        if(root==NULL)
        return true;

        if(index>=count)
        return false;

        bool left=isCBT(root->left,2*index+1,count);
        bool right=isCBT(root->right,2*index+2,count);
        if(left && right)
        return true;
        else return false;
    } 
    
    bool isMaxheap(Node* root)
    {
        //case 1 -> 0 child
        if(root->left==NULL && root->right==NULL)
        return true;

        //case 2 ->1 child(left only)
        if(root->right==NULL)
        {
            if(root->data > root->left->data)
            return true;
            else
            return false;
        }

        //case 3 -> 2 childs
        else
        {
            bool left=isMaxheap(root->left);
            bool right=isMaxheap(root->right);
            if(left && right && (root->data > root->left->data) && (root->data > root ->right->data))
            return true;
            else
            return false;
        }
    }

    public:
    bool isheap(Node* tree)
    {
        int  index=0;
        int totalNodes=countNodes(tree);
        if(isCBT(tree,index,totalNodes) && isMaxheap(tree))
        return true;
        else
        return false;
    }
};

int main()
{
    Node* root=NULL;
    root=buildTree(root);
    cout<<"\nTree Created..."<<endl;
    ques13 q;
    cout<<q.isheap(root);

    return 0;
}