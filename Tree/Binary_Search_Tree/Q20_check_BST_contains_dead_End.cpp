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

    void storeLeaf(Node* root,vector<Node*>&v,unordered_map<int,int>&m)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root);
            m[root->data]=1;
            return;
        }
        m[root->data]=1;
        storeLeaf(root->left,v,m);
        storeLeaf(root->right,v,m);
    }



    bool isDeadEnd(Node *root)
    {
        if(root==NULL)
        return false;
        
        //store all nodes
        unordered_map<int,int>m;
        
        //store all leaf nodes
        vector<Node*>v;
        
        //store all leaf in vector  && all nodes in map
        storeLeaf(root,v,m);
        
        cout<<"leaf nodes in vector"<<endl;
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        
        cout<<"\nall nodes map"<<endl;
        for(auto i:m)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        
        for(auto i:v)
        {
            if( (m[i->data+1]==1 || i->data+1<=0) && ( m[i->data-1]==1 || i->data-1<=0) )
            return true;
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
    //8 7 10 2 9 13 -1

    q.levelOrder(root);
    
    cout<<q.isDeadEnd(root);

    return 0;


}
