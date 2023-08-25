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


class ques17
{
    public:

    Node* insert(Node* root,int data,Node* &succ)
    {
        if(root==NULL)
        {
            root= new Node(data);
            return root;
        }

        if(data < root->data)
        {
            succ=root;

            root->left=insert(root->left,data,succ);
        }
        else if(data > root->data)
        root->right=insert(root->right,data,succ);

        return root;
    }

    void replaceGreater(int arr[],int n)
    {
        Node* root=NULL;

        //create BST from rever side
        for(int i=n-1;i>=0;i--)
        {
            Node* succ=NULL;

            root=insert(root,arr[i],succ);

            if(succ!=NULL)
            {
                arr[i]=succ->data;
            }
            else
            arr[i]=-1;
        }
    }

};


int main()
{
    int arr[]={8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques17 q;
    q.replaceGreater(arr,n);

    cout<<"least greater element on right side are..."<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}