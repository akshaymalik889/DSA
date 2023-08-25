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
        this->left==NULL;
        this->right=NULL;
    }
};

class ques14
{
    public:

    Node* buildTree(Node* root,int d)
    {
        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }

        else if(d<root->data)
        {
            root->left=buildTree(root->left,d);
        }
        else
        root->right=buildTree(root->right,d);

        return root;
    }

    void inputTree(Node* &root)
    {
        int data;
        cout<<"enter data for BST..."<<endl;
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

    int count;
    bool searchx(Node* root2,int k)
    {
        if(root2==NULL)
        return false;
        
        if(k==root2->data)
        return true;
        
        bool x,y;
        x=false;
        y=false;
        
        if(k < root2->data)
        x=searchx(root2->left,k);
        
        else if(k > root2->data)
        y=searchx(root2->right,k);
        
        if(x==true || y== true)
        return true;
        
        return false;
    }

    void solve(Node* root1,Node* root2,int x)
    {
        if(root1==NULL)
        return;
        
        solve(root1->left,root2,x);
        
        if(searchx(root2,x-root1->data))
        count++;
        
        solve(root1->right,root2,x);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        count=0;
        solve(root1,root2,x);
        
        return count;
    }
   

};


int main()
{

    Node* root1=NULL;
    Node* root2=NULL;

    ques14 q;
    q.inputTree(root1);
    cout<<"Tree 1 Created..."<<endl;
    //5 3 7 2 4 6 8 -1

    q.inputTree(root2);
    cout<<"Tree 2 Created..."<<endl;
    //10 6 15 3 8 11 18 -1


    q.levelOrder(root1);
    q.levelOrder(root2);

    cout<<q.countPairs(root1,root2,16);

    
    return 0;
}