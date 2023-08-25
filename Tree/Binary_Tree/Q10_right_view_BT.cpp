#include<iostream>
#include<queue>
#include<map>
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

class ques10
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

    vector<int>rightView_approach_1(Node*root)
    {
        vector<int>v;
       
        if(root==NULL)
        return v;
       
        //level,value
        map<int,int> m;
       
        //Node,level
        queue<pair<Node*,int>>q;
       
        q.push(make_pair(root,0));
       
        while(!q.empty())
        {
            pair<Node*,int>temp=q.front();
            q.pop();
           
            Node*frontNode=temp.first;
            int level=temp.second;
           
            m[level]=frontNode->data;
           
            if(frontNode->left)
            q.push(make_pair(frontNode->left,level+1));
           
            if(frontNode->right)
            q.push(make_pair(frontNode->right,level+1));
        }
       
        //push value from map to vector
        for(auto i:m)
        {
            v.push_back(i.second);
        }
       
        //    auto i=m.end();
        //    cout<<"last value:"<<i->second;
        return v;
    }

    void solve(Node*root,vector<int>&v,int level)
    {
        if(root==NULL)
        return ;

        //we entered new level
        if(level==v.size())
        v.push_back(root->data);

        solve(root->right,v,level+1);
        solve(root->left,v,level+1);
   
    }

    vector<int>rightView_approach_2(Node*root)
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

    ques10 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //10 20 40 -1 -1 60 -1 -1 30 -1 -1

    q.levelOrder(root);
    vector<int>ans=q.rightView_approach_2(root);
    q.traverse_Vector(ans);




    return 0;

}