#include<iostream>
#include<queue>
#include<unordered_map>
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

class ques24
{
    public:

    Node* buildTree(Node* root)
    {
        int data;

        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        return NULL;

        cout<<"enter data for left of "<<data<<endl;
        root->left=buildTree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=buildTree(root->right);

        return root;
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

    string solve(Node* root,unordered_map<string,int>&m)
    {
        if(root==NULL)
        return "$";
        
        string s="";
        
        if(root->right==NULL && root->left==NULL)
        {
            s= to_string(root->data);
            return s;
        }
        
        s= s + to_string(root->data);
        s= s + "$" + solve(root->left,m);
        s= s + "$" + solve(root->right,m);
        
        //store in map
        m[s]++;
        
        return s;
    }
    
    int dupSub(Node *root) {
        unordered_map<string,int>m;
    
        solve(root,m);
        
        for(auto i:m)
        {
            if(i.second >=2 )
            return true;
        }
        return false;

    }
};

int main()
{
    Node* root=NULL;
    
    ques24 q;

    root=q.buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 -1 2 4 -1 -1 5 -1 -1

    cout<<"Tree Created..."<<endl;

    q.levelOrder(root);

    cout<<q.dupSub(root)<<endl;

    return 0;
}