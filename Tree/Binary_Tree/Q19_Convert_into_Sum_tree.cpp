#include<iostream>
#include<queue>
#include<vector>
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

class ques19
{
    public:
    Node* buildTree(Node* root)
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
                cout<<temp->data<<" ";
                 
                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    

    //QUES: convert into sum tree

    int solve(Node * &root)
    {
        if(root==NULL)
        return 0;

        int l=solve(root->left);
        int r=solve(root->right);
        int x=root->data;

        root->data=l+r;
        return l+r+x;

    }
    
    void sumTree(Node* root)
    {
        solve(root);
    }


};

int main()
{
    Node* root=NULL;

    ques19 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1
    //10 -2 8 -1 -1 -4 -1 -1 6 7 -1 -1 5 -1 -1
    //3 1 -1 -1 2 -1 -1

    q.levelOrder(root); 

    q.sumTree(root);

    q.levelOrder(root);



    return 0;

}