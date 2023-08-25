#include<iostream>
#include<queue>
#include<limits.h>
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
        this->left==NULL;
        this->right=NULL;
    }
};

class ques33
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
                cout<<temp->data;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    //Approach-1
    void solve(Node* root,int n,vector<int>v,vector<int>&final)
    {
        if(root==NULL)
        return ;

        v.push_back(root->data);
        
        //if we find n node
        if(root->data==n)
        {
            final=v;
            return;
        }

        solve(root->left,n,v,final);
        solve(root->right,n,v,final);

        v.pop_back();
    }

    int kthancestor_approach_1(Node* root,int k,int n)
    {
        vector<int>v;
        vector<int>final;

        solve(root,n,v,final);

        int size=final.size();

        //invalid case
        if(k>=size)
        return -1;

        int j=0;
        int ans=0;

        for(int i=size-1;i>=0;i--)
        {
            if(j==k)
            {
                ans=final[i];
                break;
            }
            j++;
        }

        return ans;
    }


    //Approach-2
    Node* solve2(Node* root,int &k,int node)
    {
        if(root==NULL)
        return NULL;

        if(root->data==node)
        return root;

        Node*l=solve2(root->left,k,node);
        Node*r=solve2(root->right,k,node);

        if(l!=NULL && r==NULL)
        {
            k--;
            if(k<=0)
            {
                //answer lock
                k=INT_MAX;
                return root;
            }
             return l;
        }
        else if(l==NULL && r!=NULL)
        {
            k--;
            if(k<=0)
            {
                //answer lock
                k=INT_MAX;
                return root;
            }
            return r;
        }

        return NULL;      
    }

    int kthancestor_approach_2(Node* root,int k,int node)
    {
       Node* ans=solve2(root,k,node);
        if(ans==NULL || ans->data==node)//to handle k > nodes
        return -1;
        else
        return ans->data;
    }

    
};

int main()
{
    Node* root=NULL;
    
    ques33 q;

    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1 

    q.levelOrder(root);

    cout<<q.kthancestor_approach_1(root,2,4);
    cout<<q.kthancestor_approach_2(root,2,4);


    return 0;
}