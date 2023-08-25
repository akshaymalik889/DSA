#include<iostream>
#include<queue>
#include<stack>
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

class ques14
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

    int height(Node* root)
    {
        if(root==NULL)
        return 0;

        int l=height(root->left);
        int r=height(root->right);

        return max(l,r)+1;
    }

    bool isbalanced_Approach_1(Node *root)
    {
        if(root==NULL)
        return true;

        bool left=isbalanced_Approach_1(root->left);
        bool right=isbalanced_Approach_1(root->right);
        //check height
        bool diff=abs(height(root->left) - height(root->right))<=1;

        if(left && right && diff)
        return true;
        else
        return false;
    }


    pair<bool,int>isbalanced_Approach_2(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int>p;
            p.first=true;
            p.second=0;
            return p;
        }

        pair<bool,int>left=isbalanced_Approach_2(root->left);
        pair<bool,int>right=isbalanced_Approach_2(root->right);

        //check left balanced or not
        bool op1=left.first;
        //check right balanced or not
        bool op2=right.first;
    
        //check height
        bool op3=abs(left.second-right.second)<=1;

        pair<bool,int>ans;
        if(op1 && op2 && op3)
        {
            ans.first=true;
            ans.second=max(left.second,right.second)+1;
        }
        else
        {
            ans.first=false;
            ans.second=max(left.second,right.second)+1;
        }

        return ans;
    }

};

int main()
{
    Node* root=NULL;

    ques14 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1



    q.levelOrder(root);
    cout<<q.isbalanced_Approach_1(root)<<" ";

    cout<<q.isbalanced_Approach_2(root).first;


    return 0;

}