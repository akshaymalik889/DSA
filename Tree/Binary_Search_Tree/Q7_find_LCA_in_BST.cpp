#include<iostream>
#include<queue>
#include<limits.h>
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

class ques7
{
    public:
    Node* buildTree(Node* root,int d)
    {
        

        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }
        else if(d < root->data)
        root->left=buildTree(root->left,d);

        else
        root->right=buildTree(root->right,d);

        return root;
    }



    void inputData(Node* &root)
    {
        int data;
        cout<<"enter data for BST.."<<endl;
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
        return ;

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

    //Apprach 1: -> RECURSION
    Node*LCA_IN_BST_Approach_1(Node* root,Node*p,Node*q)
    {
        if(root==NULL)
        return NULL;

        if(root->data > p->data && root->data > q->data)
        return LCA_IN_BST_Approach_1(root->left,p,q);

        else if(root->data < p->data && root->data < q->data)
        return LCA_IN_BST_Approach_1(root->right,p,q);

        else
        return root;
    }

    //Approach 2 -> ITERATIVE
    Node* LCA_IN_BST_Approach_2(Node* root,Node* p,Node* q)
    {
        Node*temp=root;

        while(temp!=NULL)
        {
            if(temp->data > p->data && temp->data > q->data)
            temp=temp->left;

            else if(temp->data < p->data && temp->data < q->data)
            temp=temp->right;

            return temp;
        }
        return temp;
    }
};


int main()
{
    Node* root=NULL;

    ques7 q;
    q.inputData(root);
    cout<<"Tree Created.."<<endl;
    //4 2 5 1 3 -1

    q.levelOrder(root);

    cout<<q.LCA_IN_BST_Approach_1(root,root->left->left,root->left->right)->data<<endl;
    cout<<q.LCA_IN_BST_Approach_2(root,root->left,root->right)->data;
    

    return 0;
}