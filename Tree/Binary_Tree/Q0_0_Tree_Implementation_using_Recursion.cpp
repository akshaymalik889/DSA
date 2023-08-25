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
        this->left==NULL;
        this->right=NULL;
    }
};

class ques0
{
    public:
    Node* buildtree(Node* root)
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
        root->left=buildtree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=buildtree(root->right);

        return root;
    }

};




int main()
{
    Node* root=NULL;
    ques0 q;

    root=q.buildtree(root);
    cout<<"tree implemented..."<<endl;

    return 0;
}