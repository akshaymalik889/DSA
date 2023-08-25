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

class ques12
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

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    int solve(Node* root,int k,int &i)
    {
        if(root==NULL)
        return -1;

        //right
        int right=solve(root->right,k,i);
        if(right!=-1)
        return right;

        //root
        i++;
        if(i==k)
        return root->data;

        //left
        return solve(root->left,k,i);
    }


    int kth_Largest(Node* root,int k)
    {
        int i=0;
        int ans=solve(root,k,i);
        return ans;
    }
};


int main()
{
    Node* root=NULL;

    ques12 q;
    q.inputTree(root);
    cout<<"Tree Created..."<<endl;
    //4 9 7 1 3 -1

    q.levelOrder(root);

    cout<<q.kth_Largest(root,2);
}