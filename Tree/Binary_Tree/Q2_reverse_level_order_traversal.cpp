#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

    vector<int> level_order(Node* root)
    {
        vector<int>ans;

        if(root==NULL)
        return ans;

        queue<Node*>q;

        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                if(!q.empty())
                q.push(NULL);
            }
            
            else
            {
                ans.push_back(temp->data);
                
                if(temp->right)
                q.push(temp->right);
                
                if(temp->left)
                q.push(temp->left);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Node* root=NULL;
    // 10 20 40 -1 -1 60 -1 -1 30 -1 -1 
    ques2  q;
    root=q.buildTree(root);
    cout<<"Tree Implemented..."<<endl;
    vector<int>ans=q.level_order(root);

    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}