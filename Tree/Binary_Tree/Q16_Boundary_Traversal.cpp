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

class ques16
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

    void traverseLeft(Node* root,vector<int>&v)
    {
        if( root==NULL || (root->left==NULL && root->right==NULL) )
        return ;

        v.push_back(root->data);

        if(root->left)
        traverseLeft(root->left,v);
        else
        traverseLeft(root->right,v);
    }   

    void traverseLeaf(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return;

        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->data);
            return;
        }
    
        traverseLeaf(root->left,v);
        traverseLeaf(root->right,v);
    }

    void traverseRight(Node*root,vector<int>&v)
    {
        if( root==NULL || (root->left==NULL && root->right==NULL) )
        return ;

        if(root->right)
        traverseRight(root->right,v);
        else
        traverseRight(root->left,v);

        v.push_back(root->data);
    
    }

    vector<int> boundary_Traversal(Node* root)
    {
        /*for boundary traversal 
        step:1-> left subtree except leaf nodes
        step:2->all leaf node of left subtree and right subtree
        step:3->right subtree except leaf nodes and most important it is in reverse order
        */

        vector<int>v;
        if(root==NULL)
        return v;
        
        //first root push
        v.push_back(root->data);

        //left subtree
        traverseLeft(root->left,v);

        //Leaf Nodes
        //for left subtree
        traverseLeaf(root->left,v);
        //for right subtree
        traverseLeaf(root->right,v);

        //Right subtree
        traverseRight(root->right,v);

        return v;
    }


    void traverse_vector(vector<int>v)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }   
    }

};

int main()
{
    Node* root=NULL;

    ques16 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1
    //8 3 1 -1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1



    q.levelOrder(root); 
    vector<int>ans=q.boundary_Traversal(root);

    q.traverse_vector(ans);




    return 0;

}