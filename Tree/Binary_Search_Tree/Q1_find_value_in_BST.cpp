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

class ques1
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

    //Approach-1 (Recursion)
    
    bool searchInBST_App_1(Node* root,int val)
    {
        if(root==NULL)
        return false;

        if(root->data==val)
        return true;

        else if(val > root->data)
        return searchInBST_App_1(root->right,val);

        else
        return searchInBST_App_1(root->left,val);
    }

    //Approach-2 (Iterative)

    bool searchInBST_App_2(Node* root,int val)
    {
        Node* temp=root;

        while(temp!=NULL)
        {
            if(temp->data==val)
            return true;

            else if(val > temp->data)
            temp=temp->right;

            else
            temp=temp->left;
        }
        return false;
    }
};

int main()
{
    Node* root=NULL;

    ques1 q;
    q.takeInput(root);
    cout<<"Tree Created..."<<endl;
    //10 8 21 7 27 5 4 3 -1

    q.levelOrder(root);

    cout<<q.searchInBST_App_1(root,2);
    cout<<q.searchInBST_App_2(root,2);

    return 0;


}
