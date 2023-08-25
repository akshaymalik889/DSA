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

class ques15
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

    void inorder(Node* root,vector<float>&v)
    {
        if(root==NULL)
        return;

        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    int median(Node* root)
    {
        vector<float>v;
        inorder(root,v);
        
        int n=v.size();

        int index1=-1;
        int index2=-1;
        float median;
        if(n%2!=0)
        {
            index1=(n/2)+1;
            median=v[index1-1];
        }
        else
        {
            index1=(n/2)+1;
            index2=n/2;
            median=(v[index1-1] + v[index2-1])/2;
        }
        return median;
    }

   
};


int main()
{
    Node* root=NULL;

    ques15 q;
    q.inputTree(root);
    cout<<"Tree Created..."<<endl;
    //6 3 8 1 4 7 9 -1

    q.levelOrder(root);

    cout<<q.median(root);

   
}