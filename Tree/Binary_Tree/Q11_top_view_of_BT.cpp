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

class ques11
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

    vector<int>topView(Node* root)
    {   
        vector<int>v;
        if(root==NULL)
        return v;

        //int->hd,int->count
        map<int,int>m;

        //Node*=node,int->horizontol distance
        queue<pair<Node*,int> >q;

        q.push(make_pair(root,0));

        while(!q.empty())
        {
            pair<Node*,int>temp=q.front();
            q.pop();

            Node*frontNode=temp.first;
            int hd=temp.second;

            //if one value is present for a hd,then do nothing
            if(m.find(hd)==m.end())
            {
                m[hd]=frontNode->data;
            }

            if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

            if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));

        }
        //push answers in  vector 
        for(auto i:m)
        {
            v.push_back(i.second);
        }
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

    ques11 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //10 20 40 -1 -1 60 -1 -1 30 90 -1 -1 100 -1 -1


    q.levelOrder(root);
    vector<int>ans=q.topView(root);
    q.traverse_Vector(ans);




    return 0;

}