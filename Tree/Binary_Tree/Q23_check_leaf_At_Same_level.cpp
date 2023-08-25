#include<iostream>
#include<queue>
#include<vector>
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

class ques15
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

    void solve(Node* root ,int h,int &ma,int &ans)
    {
        if(root==NULL)
        return;
        
        if(ans==0)
        return;
        
        if(root->left==NULL && root->right==NULL)
        {
            //checking first time only
            if(ma==-1)
            ma=h;
            
            else
            {
                if(h!=ma)
                ans=0;
            }
            return;
        }
        solve(root->left,h+1,ma,ans);
        solve(root->right,h+1,ma,ans);
    }

   bool checkLeaf(Node* root)
   {
        int ans=true;
        int ma=-1;
        int h=0;
        
        solve(root,h,ma,ans);
        return ans;
   }

};

int main()
{
    Node* root=NULL;

    ques15 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 -1 3 -1 -1
    //10 20 10 -1 -1 15 -1 -1 30 -1 -1
    
    q.levelOrder(root); 
    cout<<q.checkLeaf(root);

    return 0;

}