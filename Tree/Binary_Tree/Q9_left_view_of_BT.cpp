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

class ques9
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

    vector<int>leftView_approach_1(Node*root)
    {   
        vector<int>v;

        if(root==NULL)
        return v;

        queue<Node*>q;
        //true means push in vector bcoz we need only first node 
        //for every particular level
        bool flag=true;

        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                flag=true;

                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                if(flag==true)
                {
                    v.push_back(temp->data);
                    flag=!flag;
                }

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            } 
        }
        return v;  
    }

    void solve(Node*root,vector<int>&v,int level)
    {
        if(root==NULL)
        return ;

        //we entered new level
        if(level==v.size())
        v.push_back(root->data);

        solve(root->left,v,level+1);
        solve(root->right,v,level+1);
    }

    vector<int>leftView_approach_2(Node*root)
    {
        vector<int>v;

        solve(root,v,0);
        return v;
    }

    void traverse_Vector(vector<int>v)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Node* root=NULL;

    ques9 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    q.levelOrder(root);
    vector<int>ans=q.leftView_approach_2(root);
    q.traverse_Vector(ans);


    return 0;

}