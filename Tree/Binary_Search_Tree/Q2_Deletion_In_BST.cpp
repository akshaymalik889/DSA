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

class ques2
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
        {
            root->left=buildTree(root->left,d);
        }

        else
        {
            root->right=buildTree(root->right,d);
        }
        return root;

    }

    void takeInput(Node* &root)
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

    Node* minVal(Node* root)
    {
        Node*temp=root;

        while(temp->left!=NULL)
        temp=temp->left;

        return temp;
    }

    Node* maxVal(Node* root)
    {
        Node*temp=root;

        while(temp->right!=NULL)
        temp=temp->right;

        return temp;
    }

    Node* Delete_In_BST(Node* root,int val)
    {
        //base case
        if(root==NULL)
        return root;

        if(root->data==val)
        {
            //case 1-> 0 child
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            //case 2-> 1 child

            //left child
            if(root->left!=NULL && root->right==NULL)
            {
                //store 
                Node*temp=root->left;
                delete root;
                return temp;

            }
            //right child
            else if(root->left==NULL && root->right!=NULL)
            {
                //store 
                Node*temp=root->right;
                delete root;
                return temp;
            }

            //case 3-> 2 child
            if(root->left!=NULL && root->right!=NULL)
            {
                //now we can find max value from left 
                //OR we can find min value from right
            
                //method-1 (find mini)
                // int mini=minVal(root->right)->data;

                // //copy this data into root data
                // root->data=mini;

                // root->right=Delete_In_BST(root->right,mini);
                // return root;

                //method 2(find maxi)
                int maxi=maxVal(root->left)->data;

                //copy data int root
                root->data=maxi;

                root->left=Delete_In_BST(root->left,maxi);
                return root;
            }
        }

        else if(root->data>val)
        {   
            //going in left part
            root->left=Delete_In_BST(root->left,val);
            return root;
        }
        else
        {   
            //going in right part
            root->right=Delete_In_BST(root->right,val);
            return root;
        }

        return root;
    }

};

int main()
{
    Node* root=NULL;

    ques2 q;
    q.takeInput(root);
    cout<<"Tree Created..."<<endl;
    //5 3 6 2 4 7 -1

    q.levelOrder(root);

   root=q.Delete_In_BST(root,3);
    cout<<"after deleted..."<<endl;
   q.levelOrder(root);

    return 0;


}
